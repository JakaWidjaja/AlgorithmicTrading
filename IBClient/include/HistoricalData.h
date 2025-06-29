#ifndef HISTORICAL_DATA_H
#define HISTORICAL_DATA_H

#include "Bar.h"
#include "Contract.h"
#include "TagValue.h"
#include "EClientSocket.h"
#include <string>
#include <vector>
#include <map>
#include <memory>
#include <utility>
#include <tuple>
#include <set>

class HistoricalData
{
public:
	HistoricalData() = default;
	void setClient(EClientSocket* client);

	void requestHistoricalData(int reqId,
                           const Contract& contract,
                           const std::string& endDateTime,
                           const std::string& durationStr,
                           const std::string& barSizeSetting,
                           const std::string& whatToShow,
                           int useRTH,
                           int formatDate = 1);

	void requestHistoricalData(int sleepTime,
							   const std::vector<Contract>& contracts, 
							   const std::string& endDatetime, 
							   const std::string& durationStr,
							   const std::string& barSizeSetting, 
							   const std::string& whatToShow, 
							   int useRTH = 1,
							   int formatDate = 1, 
							   int startingReqId = 1000);

	void historicalData(int reqId, const Bar& bar);
	const std::vector<Bar>& getHistoricalData(int reqId) const;

	void exportToCSV(int reqId, const std::string& filename) const; // single ticker
	void exportToCSV(const std::string& filename) const;            // multiple tickers
	void exportToCSV(const std::string& filename, const std::set<std::string>& columnNames) const; // multiple tickers and selected column
	void exportMatrixToCSV(const std::string& filename) const;
	
	std::vector<std::tuple<std::string, std::string, double>> flattenedClosePrice() const; // date, tickers, close price
	std::map<std::string, std::map<std::string, double>> matrixClosePrice() const; // column consist of date and ticker names. data are displayed as row
	
private:
	EClientSocket* clientSocket = nullptr;
	std::map<int, std::vector<Bar>> historicalDataMap;
	std::map<int, Contract> reqIdToContract;

};



#endif