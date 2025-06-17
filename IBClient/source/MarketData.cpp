#include "MarketData.h"
#include <string>
#include <mutex>
#include <memory>
#include <stdexcept>
#include <utility>

using std::string;
using std::lock_guard;
using std::mutex;
using std::shared_ptr;
using std::move;
using std::runtime_error;
using std::scoped_lock;

void MarketData::setClient(EClientSocket* client)
{
    this -> clientSocket = client; 
}

void MarketData::requestMarketData(int tickerId,
                                   const string& symbol,
                                   const string& secType,
                                   const string& exchange,
                                   const string& currency)
{
    if (!clientSocket) 
    {
        throw std::runtime_error("Client socket not set.");
    }

    Contract contract;
    contract.symbol = symbol;
    contract.secType = secType;
    contract.exchange = exchange;
    contract.currency = currency;

    TagValueListSPtr mktDataOptions;
    clientSocket -> reqMktData(tickerId, contract, "", false, false, mktDataOptions);
}

void MarketData::updatePrice(int tickerId, TickType field, double price)
{
    scoped_lock lock(mtx);
    marketData[tickerId][field] = price;
}

void MarketData::updateSize(int tickerId, TickType field, Decimal size)
{
    scoped_lock lock(mtx);
    marketData[tickerId][field] = static_cast<double>(size);
}

double MarketData::getMarketValue(int tickerId, TickType field) const
{
    scoped_lock lock(mtx);
    auto tickerIt = marketData.find(tickerId);
    if (tickerIt != marketData.end()) 
    {
        auto fieldIt = tickerIt -> second.find(field);
        if (fieldIt != tickerIt -> second.end()) 
        {
            return fieldIt -> second;
        }
    }
    return 0.0;
}

void MarketData::requestMarketDataType(int type)
{
    if (!clientSocket) 
    {
        throw runtime_error("Client socket not set.");
    }
    clientSocket -> reqMarketDataType(type);
}