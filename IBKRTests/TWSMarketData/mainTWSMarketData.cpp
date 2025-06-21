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
    client.requestMarketDataType(4);
    std::this_thread::sleep_for(std::chrono::seconds(3));
    
    // Get market data
    client.requestMarketData(10, "BAC", "STK", "SMART", "USD");
    
    double bid = client.getMarketValue(10, DELAYED_LAST);
    std::this_thread::sleep_for(std::chrono::seconds(3));

    double ask = client.getMarketValue(10, DELAYED_LAST);
    std::this_thread::sleep_for(std::chrono::seconds(3));

    cout << "bid: " << bid << endl;
    cout << "ask: " << ask << endl;


    client.disconnect();
    
    return 0;
}