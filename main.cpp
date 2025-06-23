#include "IBClient.h"
#include "Config.h"
#include "ConfigTWS.h"
#include "ConfigModel.h"
#include "ConfigParams.h"
#include "ConfigContract.h"
#include "MakeContract.h"
#include "Contract.h"
#include "Combinations.h"

#include <iostream>
#include <string>
#include <memory>
#include <vector> 
#include <sstream>
#include <iomanip>
#include <set>

using std::string;
using std::shared_ptr;
using std::vector;
using std::set;

using std::cout;
using std::endl;

std::string TodayDate() 
{
    auto now = std::chrono::system_clock::now();
    std::time_t t = std::chrono::system_clock::to_time_t(now);
    std::ostringstream oss;
    oss << std::put_time(std::localtime(&t), "%Y%m%d");
    return oss.str();
}

int main() 
{   
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

    set<string> colNames = {"date", "symbol", "close"};
    client.exportHistoricalDataToCSV("/home/lun/Desktop/Folder 2/AlgoTradingC++/strategy/data/USEquity" + TodayDate() + ".csv", 
                                     colNames);

    auto data = client.getHistoricalDataHandler().flattenedClosePrice();
    for (const auto& [date, ticker, close] : data) {
        std::cout << date << ", " << ticker << ", " << close << "\n";
    }
    
    /*
    // Model calibration and create signal 
    vector<string> tickers;
    int count = 0;
    for(const auto& t : contractConfig -> getContracts())
    {
        tickers.push_back(t.symbol);
    }
    
    Combinations comb;
    auto portCombinations = comb.generate(tickers, modelConfig -> getStockCombinations()); 
    */







    // Disconnect to TWS
    client.disconnect();
    
    return 0;
}