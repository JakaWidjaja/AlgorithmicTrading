#include "IBClient.h"
#include <chrono>
#include <thread>
#include <iostream>

using namespace std;

int main() 
{
    IBClient client;

    // Connect to TWS or IB Gateway
    string host = "127.0.0.1";
    int port = 7497;
    int clientId = 1;
    client.connect(host, port, clientId);

    // Define the contract (AAPL stock)
    Contract contract;
    contract.symbol = "AAPL";
    contract.secType = "STK";
    contract.exchange = "SMART";
    contract.currency = "USD";

    // Ensure you get a valid order ID before sending request
    client.requestNextValidId();
    std::this_thread::sleep_for(std::chrono::seconds(2));

    // Request historical data
    int reqId = 9001;
    string endDateTime = "";  // now
    string duration = "1 D";
    string barSize = "5 mins";
    string whatToShow = "TRADES";
    int useRTH = 1;

    client.requestHistoricalData(
        reqId,
        contract,
        endDateTime,
        duration,
        barSize,
        whatToShow,
        useRTH, 1
    );

    // Wait for the data to arrive
    std::this_thread::sleep_for(std::chrono::seconds(5));

    // Export the data to CSV
    client.exportHistoricalDataToCSV(reqId, "/home/lun/Desktop/Folder 2/AlgoTradingC++/IBKRTests/TWSHistoricalData/AAPL_data.csv");

    // Disconnect from TWS
    client.disconnect();

    return 0;
}