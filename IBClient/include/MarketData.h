#ifndef MARKET_DATA_H
#define MARKET_DATA_H

#include "Contract.h"
#include "EWrapper.h"
#include "TagValue.h"
#include "EClientSocket.h"
#include <map>
#include <mutex>
#include <string>
#include <memory>

class MarketData {
public:
    MarketData() = default;

    void setClient(EClientSocket* client);
    void requestMarketData(int tickerId,
                           const std::string& symbol,
                           const std::string& secType,
                           const std::string& exchange,
                           const std::string& currency);

    void updatePrice(int tickerId, TickType field, double price);
    void updateSize(int tickerId, TickType field, Decimal size);
    double getMarketValue(int tickerId, TickType field) const;

    void requestMarketDataType(int type);

private:
    EClientSocket* clientSocket = nullptr;
    mutable std::mutex mtx;
    std::map<int, std::map<TickType, double>> marketData;
};
#endif