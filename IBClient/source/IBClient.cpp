#include "IBClient.h"
#include "OrderManager.h"
#include "EClientSocket.h"
#include "Contract.h"
#include <string>
#include <vector>
#include <memory>
#include <tuple>
#include <set>
#include <map>

using std::string;
using std::vector;
using std::shared_ptr;
using std::tuple;
using std::set;
using std::map;

IBClient::IBClient() :IBClientCore()
{
    EClientSocket* socket = getClientSocket();
    marketData.setClient(socket);
    histData.setClient(socket);
    orderManager.setClient(socket);
}

IBClient::~IBClient()
{}

//Historical Data
void IBClient::historicalData(TickerId reqId, const Bar& bar)
{
	histData.historicalData(reqId, bar);
}

void IBClient::requestHistoricalData(int reqId, const Contract& contract,
                                     const string& endDateTime, const string& durationStr,
                                     const string& barSizeSetting, const string& whatToShow,
                                     int useRTH, int formatDate)
{
	histData.requestHistoricalData(reqId, contract, endDateTime, durationStr, barSizeSetting, whatToShow,
                                    useRTH, formatDate);
}

void IBClient::requestHistoricalData(int sleepTime,
                               const std::vector<Contract>& contracts, 
                               const std::string& endDatetime, 
                               const std::string& durationStr,
                               const std::string& barSizeSetting, 
                               const std::string& whatToShow, 
                               int useRTH,
                               int formatDate, 
                               int startingReqId)
{
    histData.requestHistoricalData(sleepTime, contracts, endDatetime, durationStr, barSizeSetting, 
                                   whatToShow, useRTH, formatDate, startingReqId);
}

const vector<Bar>& IBClient::getHistoricalData(int reqId) const
{
	return histData.getHistoricalData(reqId);
}

void IBClient::exportHistoricalDataToCSV(int reqId, const string& filename) const 
{
    histData.exportToCSV(reqId, filename);
}

void IBClient::exportHistoricalDataToCSV(const string& filename) const 
{
    histData.exportToCSV(filename);
}

void IBClient::exportHistoricalDataToCSV(const string& filename, const set<string>& columnNames) const 
{
    histData.exportToCSV(filename, columnNames);
}

void IBClient::exportMatrixToCSV(const string& filename) const
{
    histData.exportMatrixToCSV(filename);
}

vector<tuple<string, string, double>> IBClient::flattenedClosePrice() const
{
    return histData.flattenedClosePrice();
}

map<string, map<string, double>> IBClient::matrixClosePrice() const
{
    return histData.matrixClosePrice();
} 


// Market data
void IBClient::requestMarketDataType(int type) 
{
    marketData.requestMarketDataType(type);
}

void IBClient::requestMarketData(int tickerId, const string& symbol,
                                 const string& secType, const string& exchange,
                                 const string& currency)
{
    marketData.requestMarketData(tickerId, symbol, secType, exchange, currency);
}

void IBClient::tickPrice(TickerId tickerId, TickType field, double price, const TickAttrib&) 
{
    marketData.updatePrice(tickerId, field, price);
}

void IBClient::tickSize(TickerId tickerId, TickType field, Decimal size) 
{
    marketData.updateSize(tickerId, field, size);
}

double IBClient::getMarketValue(int tickerId, TickType field) const 
{
    return marketData.getMarketValue(tickerId, field);
}



void IBClient::historicalDataEnd(int reqId, const string& start, const string& end) 
{}


void IBClient::nextValidId(OrderId orderId) 
{
    std::cout << "Received nextValidId: " << orderId << std::endl;
    orderManager.setNextOrderId(orderId);
}


// Order managements
void IBClient::placeMarketOrder(const Contract& contract, double quantity, const string& direction)
{
    orderManager.placeMarketOrder(contract, quantity, direction);
}

void IBClient::placeLimitOrder(const Contract& contract, double quantity, const string& direction, double limitPrice)
{
    orderManager.placeLimitOrder(contract, quantity, direction, limitPrice);
}

void IBClient::placeStopOrder(const Contract& contract, double quantity, const string& direction, double stopPrice)
{
    orderManager.placeStopOrder(contract, quantity, direction, stopPrice);
}

void IBClient::placeStopLimitOrder(const Contract& contract, double quantity, const string& direction, double stopPrice, double limitPrice)
{
    orderManager.placeStopLimitOrder(contract, quantity, direction, stopPrice, limitPrice);
}

void IBClient::placeTrailingStopOrder(const Contract& contract, double quantity, const string& direction, double trailingAmount)
{
    orderManager.placeTrailingStopOrder(contract, quantity, direction, trailingAmount);
}

void IBClient::placeTrailingStopLimitOrder(const Contract& contract, double quantity, const string& direction, double trailingAmount, double limitOffset)
{
    orderManager.placeTrailingStopLimitOrder(contract, quantity, direction, trailingAmount, limitOffset);
}

void IBClient::placeMarketOnCloseOrder(const Contract& contract, double quantity, const string& direction)
{
    orderManager.placeMarketOnCloseOrder(contract, quantity, direction);
}

void IBClient::placeLimitOnCloseOrder(const Contract& contract, double quantity, const string& direction, double limitPrice)
{
    orderManager.placeLimitOnCloseOrder(contract, quantity, direction, limitPrice);
}

void IBClient::placePeggedToMarketOrder(const Contract& contract, double quantity, const string& direction, double offset)
{
    orderManager.placePeggedToMarketOrder(contract, quantity, direction, offset);
}

void IBClient::placePeggedToMidpointOrder(const Contract& contract, double quantity, const string& direction, double offset)
{
    orderManager.placePeggedToMidpointOrder(contract, quantity, direction, offset);
}

void IBClient::placeRelativeOrder(const Contract& contract, double quantity, const string& direction, double offset)
{
    orderManager.placeRelativeOrder(contract, quantity, direction, offset);
}

void IBClient::placeOcaGroupOrders(const vector<tuple<Contract, double, string, string, double>>& orders, const string& ocaGroup)
{
    orderManager.placeOcaGroupOrders(orders, ocaGroup);
}

void IBClient::placeBracketOrder(const Contract& contract, double quantity, double entryPrice, double takeProfitPrice, double stopLossPrice, const string& direction)
{
    orderManager.placeBracketOrder(contract, quantity, entryPrice, takeProfitPrice, stopLossPrice, direction);
}

void IBClient::placeTimeBasedOrder(const Contract& contract, double quantity, const string& direction, const string& orderType, double price, const string& goodAfterTime, const string& goodTillDate)
{
    orderManager.placeTimeBasedOrder(contract, quantity, direction, orderType, price, goodAfterTime, goodTillDate);
}

void IBClient::cancelOrder(int orderId)
{
    orderManager.cancelOrder(orderId);
}

void IBClient::cancelAllOrders()
{
    orderManager.cancelAllOrders();
}

void IBClient::orderStatus(OrderId orderId, const std::string& status, Decimal filled,
                           Decimal remaining, double avgFillPrice, long long permId,
                           int parentId, double lastFillPrice, int clientId,
                           const std::string& whyHeld, double mktCapPrice)
{
    std::cout << "[ORDER STATUS] ID: " << orderId
              << ", Status: " << status
              << ", Filled: " << filled
              << ", AvgFillPrice: " << avgFillPrice << "\n";
}

void IBClient::error(int id, time_t time, int errorCode, const std::string& errorString, const std::string& advancedOrderRejectJson)
{
    std::cerr << "[ERROR] ID: " << id
              << ", Code: " << errorCode
              << ", Message: " << errorString
              << std::endl;
}
