#include "HistoricalData.h"
#include "Contract.h"
#include <iostream>
#include <vector>
#include <string>
#include <utility>
#include <stdexcept>
#include <fstream>
#include <thread>
#include <chrono>
#include <tuple>
#include <set>
#include <algorithm>

using std::vector;
using std::string;
using std::shared_ptr;
using std::move;
using std::runtime_error;
using std::to_string;
using std::ofstream;
using std::set;
using std::tuple;
using std::sort;
using std::get;

void HistoricalData::setClient(EClientSocket* client) 
{
    this -> clientSocket = client; 
}

void HistoricalData::requestHistoricalData(int reqId,
                                           const Contract& contract,
                                           const string& endDateTime,
                                           const string& durationStr,
                                           const string& barSizeSetting,
                                           const string& whatToShow,
                                           int useRTH,
                                           int formatDate)
{
    if (!clientSocket) 
    {
        throw std::runtime_error("Client socket not set.");
    }

    historicalDataMap[reqId].clear();

    clientSocket->reqHistoricalData(reqId, contract,
                                    endDateTime,
                                    durationStr,
                                    barSizeSetting,
                                    whatToShow,
                                    useRTH,
                                    formatDate,
                                    false, TagValueListSPtr());
}

// Multiple contracts
void HistoricalData::requestHistoricalData(int sleepTime,
                                           const vector<Contract>& contracts, 
                                           const string& endDateTime, 
                                           const string& durationStr, 
                                           const string& barSizeSetting, 
                                           const string& whatToShow, 
                                           int useRTH, 
                                           int formatDate, 
                                           int startingReqId)
{
    if(!clientSocket)
    {
        throw::runtime_error("Client socket not set.");
    }

    int reqId = startingReqId;
    for(const auto& c : contracts)
    {
        historicalDataMap[reqId].clear();
        reqIdToContract[reqId] = c;

        clientSocket -> reqHistoricalData(reqId, c, endDateTime, durationStr, barSizeSetting, 
                                          whatToShow, useRTH, formatDate, false, TagValueListSPtr());

        std::this_thread::sleep_for(std::chrono::seconds(sleepTime));
        ++reqId;
    }
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

vector<tuple<string, string, double>> HistoricalData::flattenedClosePrice() const
{
    vector<tuple<string, string, double>> flatData; // date, symbol, close

    for(const auto& [reqId, bars] : historicalDataMap)
    {
        auto cit = reqIdToContract.find(reqId);
        if(cit == reqIdToContract.end())
            {continue;}

        const string& symbol = cit -> second.symbol;

        for(const auto& bar : bars)
        {
            flatData.emplace_back(bar.time, symbol, bar.close);
        }
    }

    sort(flatData.begin(), flatData.end(), [](const auto& a, const auto& b){return get<0>(a) < get<0>(b);});

    return flatData;
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

// Multiple contracts
void HistoricalData::exportToCSV(const string& filename) const
{
    ofstream outFile(filename);
    if(!outFile.is_open())
    {
        throw runtime_error("Failed to open file: " + filename);
    }

    outFile << "symbol,date,open,high,low,close,volume,count,wap\n";

    for(const auto&[reqId, bars] : historicalDataMap)
    {
        auto cit = reqIdToContract.find(reqId);
        if(cit == reqIdToContract.end())
            {continue;}

        const string& symbol = cit -> second.symbol;

        for(const auto& bar : bars)
        {
            outFile << symbol << "," << bar.time << "," << bar.open << "," << bar.high << ","
                    << bar.low << "," << bar.close << "," << bar.volume << ","
                    << bar.count << "," << bar.wap << "\n";
        }
    }

    outFile.close();
}

void HistoricalData::exportToCSV(const string& filename, const set<string>& columnNames) const
{
    ofstream outFile(filename);
    if(!outFile.is_open())
    {
        throw runtime_error("Failed to open file: " + filename);
    }

    if (columnNames.count("symbol"))  outFile << "symbol,";
    if (columnNames.count("date"))    outFile << "date,";
    if (columnNames.count("open"))    outFile << "open,";
    if (columnNames.count("high"))    outFile << "high,";
    if (columnNames.count("low"))     outFile << "low,";
    if (columnNames.count("close"))   outFile << "close,";
    if (columnNames.count("volume"))  outFile << "volume,";
    if (columnNames.count("count"))   outFile << "count,";
    if (columnNames.count("wap"))     outFile << "wap,";
    outFile.seekp(-1, std::ios_base::end); // remove trailing comma
    outFile << "\n";

    for(const auto& [reqId, bars] : historicalDataMap)
    {
        auto cit = reqIdToContract.find(reqId);
        if(cit == reqIdToContract.end())
            {continue;}

        const string& symbol = cit -> second.symbol;

        for(const auto& bar : bars)
        {
            if (columnNames.count("symbol"))  outFile << symbol     << ",";
            if (columnNames.count("date"))    outFile << bar.time   << ",";
            if (columnNames.count("open"))    outFile << bar.open   << ",";
            if (columnNames.count("high"))    outFile << bar.high   << ",";
            if (columnNames.count("low"))     outFile << bar.low    << ",";
            if (columnNames.count("close"))   outFile << bar.close  << ",";
            if (columnNames.count("volume"))  outFile << bar.volume << ",";
            if (columnNames.count("count"))   outFile << bar.count  << ",";
            if (columnNames.count("wap"))     outFile << bar.wap    << ",";
            outFile.seekp(-1, std::ios_base::cur); // remove trailing comma
            outFile << "\n";
        }
    }

    outFile.close();
}