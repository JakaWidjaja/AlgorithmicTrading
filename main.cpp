#include "IBClient.h"
#include "Contract.h"
#include "Config.h"
#include "ConfigTWS.h"
#include "ConfigModel.h"
#include "ConfigParams.h"
#include "ConfigContract.h"
#include "MethodOfMoment.h"
#include "MaxLikelihood.h"
#include "Combinations.h"
#include "Permutations.h"
#include "CombinatoricsGenerator.h"
#include "Autocovariance.h"
#include "DoubleSMA.h"
#include "SingleSMA.h"
#include "HurstExponent.h"
#include "VarianceRatio.h"
#include "HalfLife.h"
#include "SavitzkyGolay.h"

#include <iostream>
#include <thread>
#include <chrono>
#include <memory>
#include <iomanip> 
#include <ctime>
#include <vector>

using std::string;
using std::cout;
using std::endl;
using std::shared_ptr;
using std::make_shared;
using std::vector;

int main() {
    
    // Config file path
    string configPath = "/home/lun/Desktop/Folder 2/AlgoTradingC++/config/configMeanRevertPortEOD.xlsx";

    // Initialised objects
    
    Config config(configPath);

    shared_ptr<ConfigTWS>      twsConfig      = config.getTWSConfig();
    shared_ptr<ConfigModel>    modelConfig    = config.getModelConfig();
    shared_ptr<ConfigParams>   paramsConfig   = config.getParamsConfig();
    shared_ptr<ConfigContract> contractConfig = config.getContractConfig();

    cout << "Host: "             << twsConfig->getHost()              << endl;
    cout << "Port: "             << twsConfig->getPort()              << endl;
    cout << "Client ID: "        << twsConfig->getClientId()          << endl;
    cout << "Calibration data: " << modelConfig->getCalibrationData() << endl; 
    cout << "Top stocks: "       << modelConfig->getTopStocks()       << endl;
    cout << "Lookback: "         << paramsConfig->getLookback()       << endl;
    cout << "Interval: "         << paramsConfig->getInterval()       << endl;

    cout << endl;
    /*
    for(const auto& c : contractConfig->getContracts())
    {
        cout << c.symbol << ", " << c.secType << ", " << c.exchange << ", " << c.currency;
        if(c.expiry) cout << ", Expiry: " << *c.expiry;
        if(c.right) cout << ", Right: " << *c.right;
    }

    auto openTime  = twsConfig->getMarketOpenTime();
    auto closeTime = twsConfig->getMarketCloseTime();
    
    int count(0);
    while(std::chrono::system_clock::now() > openTime)
    {
        std::time_t nowC = std::chrono::system_clock::to_time_t(std::chrono::system_clock::now());
        cout << std::put_time(std::localtime(&nowC), "%H:%M:%S") << endl;

        std::this_thread::sleep_for(std::chrono::seconds(1));

        if(++count == 5)
            {break;}
    }

    // Ornstein Uhlenbeck calibration
    vector<double> timeSeries = {0.5, 0.6, 0.58, 0.55, 0.54, 0.53, 0.51};
    shared_ptr<OrnsteinUhlenbeck> calibMOM = make_shared<MethodOfMoment>();
    shared_ptr<OrnsteinUhlenbeck> calibMLE = make_shared<MaxLikelihood>();

    vector<double> paramsMOM = calibMOM->calibrate(timeSeries);
    vector<double> paramsMLE = calibMLE->calibrate(timeSeries);
    cout << paramsMOM[0] << ", " << paramsMOM[1] << ", " << paramsMOM[2] << endl;
    cout << paramsMLE[0] << ", " << paramsMLE[1] << ", " << paramsMLE[2] << endl; 

    
    // Combinations and permutations
    vector<string> tickers = {"AAPL", "GOOG", "MSFT", "AMZN", "TSLA", "NVDA", "META", "NFLX", "BABA", "IBM"};

    auto comb = make_shared<Combinations>();
    auto perm = make_shared<Permutations>();

    CombinatoricsGenerator gen(tickers, comb);

    cout << "\nCombinations of 3: \n";
    auto combos = gen.compute(3);
    for(const auto& c : combos)
    {
        for(const auto& s : c)
        {
            cout << s << " ";

        }
        cout << "\n";
    }

    gen.setMethod(perm);
    std::cout << "\nPermutations of 3:\n";
    auto perms = gen.compute(3);
    for (const auto& p : perms) {
        for (const auto& s : p) std::cout << s << " ";
        std::cout << "\n";
    }

    // Autocovariance
    vector<double> data = {1.2, 2.3, 3.1, 2.8, 3.7, 2.5, 1.9};
    int lag = 2;

    Autocovariance acf(2);
    acf.compute(data);
    double res = acf.getValue();
    cout << "Autocovariance: " << res << endl;

    // Double SMA
    vector<double> prices = {100.0, 101.0, 102.5, 104.0, 103.0, 102.0, 101.5, 100.5, 99.5, 98.0, 97.5, 96.0, 95.5, 96.5, 97.0};
    int shortWindow = 3;
    int longWindow = 5;
    DoubleSMA dsma(shortWindow, longWindow);
    dsma.compute(prices);
    vector<double> resSMA = dsma.getValue();
    cout << "Double SMA (short - long): " << endl;
    for(size_t i = 0; i < resSMA.size(); ++i)
    {
        cout << "index " << i + (longWindow -1) << ": " << resSMA[i] << endl;
    }

    // Single SMA
    vector<double> datassma = {1, 2, 3, 4, 5, 6, 7};
    SingleSMA ssma(3);
    ssma.compute(datassma);
    for(const auto& val : ssma.getValue())
    {
        cout << val << " "; 
    }
    cout << endl;

    // Hurst Exponent
    std::vector<double> dataH = {100, 101, 102, 99, 98, 97, 100, 105, 110, 108, 100, 101, 102, 99, 98, 97, 100, 105, 110, 108, 100, 100};

    HurstExponent hurstCalc;
    hurstCalc.compute(dataH);
    std::cout << "Hurst Exponent: " << hurstCalc.getValue() << std::endl;

    // Variance Ratio
    std::vector<double> datavr = {110, 101, 102, 99, 98, 97, 100, 105, 110, 108, 100, 101, 102, 99, 98, 97, 100, 105, 110, 108, 100, 100};
    VarianceRatio vr(2); // lag = 2
    vr.compute(datavr);
    std::cout << "Variance Ratio: " << vr.getValue() << std::endl;

    // Variance Ratio
    HalfLife hl;
    hl.compute(datavr);
    cout << "Half Life: " << hl.getValue() << endl;

    // Savitzky Golay smoothing
    vector<double> dataSG = {10, 11, 15, 14, 13, 16, 14, 13, 15, 16};
    SavitzkyGolay filter(5, 2);
    filter.compute(dataSG);

    auto smoothed = filter.getValue();
    cout << "Savitzky Golay: ";
    for(double v : smoothed)
    {
        cout << v << " ";
    }
    cout << endl;
    */

    // Connect to TWS
    IBClient client;
    string host = "127.0.0.1";
    int port    = 7497;
    int id      = 8;
    client.connect(host, port, id);
    client.requestMarketDataType(4);
    std::this_thread::sleep_for(std::chrono::seconds(3));
    /*
    // Get market data
    client.requestMarketData(10, "BAC", "STK", "SMART", "USD");
    
    double bid = client.getMarketValue(10, DELAYED_LAST);
    std::this_thread::sleep_for(std::chrono::seconds(3));
    double ask = client.getMarketValue(10, DELAYED_LAST);
    std::this_thread::sleep_for(std::chrono::seconds(3));

    cout << "bid: " << bid << endl;
    cout << "ask: " << ask << endl;
    */
    Contract contract;
    contract.symbol = "BHP";
    contract.secType = "STK";
    contract.exchange = "SMART";
    contract.currency = "AUD";

    client.requestNextValidId();
    std::this_thread::sleep_for(std::chrono::seconds(3));

    // Print a fake order ID to test
    std::cout << "[TEST] OrderManager internal orderIdCounter should now be valid.\n";

    client.placeMarketOrder(contract, std::stod("33"), "BUY");
    std::this_thread::sleep_for(std::chrono::seconds(3));

    //client.placeMarketOrder(contract, 100, "BUY");
    //std::this_thread::sleep_for(std::chrono::seconds(3));

    //client.cancelAllOrders();

    client.disconnect();
    
    return 0;
}