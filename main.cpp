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

int main() 
{
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