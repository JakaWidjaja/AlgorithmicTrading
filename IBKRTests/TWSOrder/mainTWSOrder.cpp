#include "IBClient.h"

#include <iostream>
#include <thread>
#include <chrono>
#include <ctime>

using std::string;
using std::cout;
using std::endl;

int main() 
{
    // Connect to TWS
    IBClient client;
    string host = "127.0.0.1";
    int port    = 7497;
    int id      = 8;
    client.connect(host, port, id);

    Contract contract;
    contract.symbol = "AMZN";
    contract.secType = "STK";
    contract.exchange = "SMART";
    contract.currency = "USD";

    client.requestNextValidId();
    std::this_thread::sleep_for(std::chrono::seconds(3));


    client.placeMarketOrder(contract, std::stod("33"), "BUY");
    std::this_thread::sleep_for(std::chrono::seconds(3));

    client.placeLimitOrder(contract, 100, "BUY", 185.00);
    std::this_thread::sleep_for(std::chrono::seconds(3));

    // Cancel Orders
    client.cancelAllOrders();

    client.disconnect();
    
    return 0;
}