#include "IBClient.h"
#include "Contract.h"
#include "Config.h"
#include "ConfigTWS.h"
#include "ConfigModel.h"
#include "ConfigParams.h"
#include "ConfigContract.h"

#include <iostream>
#include <memory>
#include <chrono>
#include <thread>
#include <iomanip>

using std::string;
using std::cout;
using std::endl;
using std::shared_ptr;
using std::make_shared;
using std::put_time;

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

    
    return 0;
}