#include "IBClient.h"
#include "Config.h"
#include "ConfigTWS.h"
#include "ConfigModel.h"
#include "ConfigParams.h"
#include "ConfigContract.h"
#include "MakeContract.h"
#include "Contract.h"
#include "MeanRevertingPortfolio.h"
#include "PortfolioSelection.h"
#include "Utilities.h"
#include "GenerateSignals.h"
#include "HurstExponent.h"
#include "VarianceRatio.h"
#include "HalfLife.h"
#include "SingleSMA.h"
#include "SavitzkyGolay.h"

#include <Eigen/Dense>
#include <iostream>
#include <string>
#include <memory>
#include <vector> 
#include <sstream>
#include <iomanip>
#include <set>
#include <map>

using std::string;
using std::shared_ptr;
using std::make_shared;
using std::vector;
using std::set;
using std::map;

using std::cout;
using std::endl;

int main() 
{   
    Utilities util;

    // Sleep time
    int sleepTime = 2;

    // Get config
    string configPath = "/home/lun/Desktop/Folder 2/AlgoTradingC++/config/configMeanRevertPortEOD.xlsx";
    Config config(configPath);

    shared_ptr<ConfigTWS>      twsConfig      = config.getTWSConfig();
    shared_ptr<ConfigModel>    modelConfig    = config.getModelConfig();
    shared_ptr<ConfigParams>   paramsConfig   = config.getParamsConfig();
    shared_ptr<ConfigContract> contractConfig = config.getContractConfig();

    // Connect to TWS
    IBClient client;
    string host = twsConfig -> getHost();
    int port    = twsConfig -> getPort();
    int id      = twsConfig -> getClientId();
    client.connect(host, port, id);
    client.requestMarketDataType(twsConfig -> getMarketDataType()); // 1 for live, 4 for delayed
    std::this_thread::sleep_for(std::chrono::seconds(sleepTime));

    // Create contracts
    MakeContract cont(configPath);
    vector<Contract> contract = cont.contractList();

    // Get historical data
    client.requestNextValidId();
    client.requestHistoricalData(sleepTime, 
                                 contract, 
                                 "", 
                                 paramsConfig -> getLookback(), 
                                 paramsConfig -> getInterval(), 
                                 "TRADES");

    auto histData = client.matrixClosePrice();
    client.exportMatrixToCSV("/home/lun/Desktop/Folder 2/AlgoTradingC++/strategy/data/USEquity" + util.TodayDate() + ".csv");

    
    // Model calibration and create signal 
    // Select stocks to trade

    vector<string> tickers;
    int count = 0;
    for(const auto& t : contractConfig -> getContracts())
    {
        tickers.push_back(t.symbol);
    }

    Eigen::MatrixXd priceMatrix;
    vector<string> dateList;
    vector<string> stockList;
    PortfolioSelection::reshapePriceMatrixData(histData, priceMatrix, dateList, stockList); // re-shape hist Data
    
    MeanRevertingPortfolio mrPort(modelConfig -> getTopStocks(), modelConfig -> getCalibrationData());
    vector<vector<string>> portCombinations = mrPort.stockSelection(priceMatrix, stockList, modelConfig -> getStockCombinations(), "low");
    vector<portfolioRow> portWeights = mrPort.portfolioPositions(portCombinations, priceMatrix, stockList, modelConfig -> getLongShortIndicator());
    
    // Make some adjustments. 
    
    set<string> uniqueTickers = util.uniqueTickers(portWeights); // Get unique tickers.
    map<string, map<string, double>> filteredHistData = util.filteredHistData(uniqueTickers, histData); // Filter hist data to just the unique ticks.
    vector<Contract> uniqueContracts = util.uniqueContracts(contract, uniqueTickers); // Get the unique contracts. 

    // Create request market data
    int tickerId = 1000;
    map<string, int> symbolToTickerId;
    for(const auto& c : uniqueContracts)
    {
        string symbol = c.symbol;
        symbolToTickerId[symbol] = tickerId;
        client.requestMarketData(tickerId, symbol, c.secType, c.exchange, c.currency);
        ++tickerId;
    }
    std::this_thread::sleep_for(std::chrono::seconds(sleepTime));


    // while loop starts here

    // append to hist data
    string today = util.TodayDate();
    map<string, double>& todayRow = filteredHistData[today];
    for(const auto& [symbol, id] : symbolToTickerId)
    {
        double price = client.getMarketValue(id, DELAYED_LAST);
        std::this_thread::sleep_for(std::chrono::seconds(sleepTime));
        
        if(std::isfinite(price))
        {
            todayRow[symbol] = price;
        }
    }

    Eigen::MatrixXd combineData;
    vector<string> finalDateList;
    vector<string> finalStockList;
    PortfolioSelection::reshapePriceMatrixData(filteredHistData, combineData, finalDateList, finalStockList);
    //util.exportFilteredHistDataToCSV("/home/lun/Desktop/Folder 2/AlgoTradingC++/strategy/data/filteredHistData.csv", filteredHistData);
    //util.exportMatrixToCSV("/home/lun/Desktop/Folder 2/AlgoTradingC++/strategy/data/combineData.csv", combineData, finalDateList, finalStockList);
    //util.exportListToCSV("/home/lun/Desktop/Folder 2/AlgoTradingC++/strategy/data/finalDatelist.csv", finalDateList, "Date");
    //util.exportListToCSV("/home/lun/Desktop/Folder 2/AlgoTradingC++/strategy/data/finalStockList.csv", finalStockList, "Stock");

    // Technical Indicators
    auto hurst = make_shared<HurstExponent>();
    auto vr    = make_shared<VarianceRatio>();
    auto hl    = make_shared<HalfLife>();
    auto sma   = make_shared<SingleSMA>(modelConfig -> getDoubleSMAShortWindow());
    auto sg    = make_shared<SavitzkyGolay>(31, 10);

    // Generate signals
    GenerateSignals generator(modelConfig, 
                              hurst, vr, hl, sma, sg,
                              portWeights, 
                              modelConfig -> getInvestmentAmount());

    auto [meanRevertSignal, trendSignal] = generator.signals(combineData);

    // Disconnect to TWS
    client.disconnect();
    
    return 0;
}