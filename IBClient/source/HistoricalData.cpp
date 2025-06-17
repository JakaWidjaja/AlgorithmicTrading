#include "HistoricalData.h"
#include <iostream>
#include <vector>
#include <string>
#include <utility>
#include <stdexcept>
#include <fstream>

using std::vector;
using std::string;
using std::shared_ptr;
using std::move;
using std::runtime_error;
using std::to_string;
using std::ofstream;

void HistoricalData::setClient(EClientSocket* client) 
{
    this -> clientSocket = client; 
}

void HistoricalData::requestHistoricalData(int reqId,
                                           const string& symbol, 
                                           const string& secType,
                                           const string& exchange, 
                                           const string& currency,
                                           const string& endDateTime, 
                                           const string& durationStr,
                                           const string& barSizeSetting, 
                                           const string& whatToShow,
                                           int useRTH, int formatDate)
{
	if (!clientSocket) {
        throw std::runtime_error("Client socket not set.");
    }

	Contract contract;
	contract.symbol   = symbol;
	contract.secType  = secType;
	contract.exchange = exchange;
	contract.currency = currency;

	historicalDataMap[reqId].clear();
	clientSocket -> reqHistoricalData(reqId, contract, endDateTime, 
								durationStr, barSizeSetting, whatToShow, 
								useRTH, formatDate, false, TagValueListSPtr());
}

void HistoricalData::historicalData(int reqId, const Bar& bar)
{
	historicalDataMap[reqId].push_back(bar);
}

const vector<Bar>& HistoricalData::getHistoricalData(int reqId) const
{
	static const vector<Bar> empty;
	auto it = historicalDataMap.find(reqId);
	return it != historicalDataMap.end() ? it -> second : empty;
}

void HistoricalData::exportToCSV(int reqId, const string& filename) const
{
	auto it = historicalDataMap.find(reqId);
    if (it == historicalDataMap.end()) {
        throw runtime_error("No data found for request ID: " + to_string(reqId));
    }

    ofstream outFile(filename);
    if (!outFile.is_open()) {
        throw runtime_error("Failed to open file: " + filename);
    }

    outFile << "Date,Open,High,Low,Close,Volume,Count,WAP\n";
    for (const auto& bar : it -> second) {
        outFile << bar.time << ","
                << bar.open << ","
                << bar.high << ","
                << bar.low << ","
                << bar.close << ","
                << bar.volume << ","
                << bar.count << ","
                << bar.wap << "\n";
    }

    outFile.close();
}