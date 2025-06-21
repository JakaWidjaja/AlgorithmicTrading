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

	void historicalData(int reqId, const Bar& bar);
	const std::vector<Bar>& getHistoricalData(int reqId) const;

	void exportToCSV(int reqId, const std::string& filename) const;
	
private:
	EClientSocket* clientSocket = nullptr;
	std::map<int, std::vector<Bar>> historicalDataMap;

};

#endif