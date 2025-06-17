#include "MarketDataStore.h"
#include <mutex>


MarketDataStore::MarketDataStore()
{}

MarketDataStore::~MarketDataStore()
{}

void MarketDataStore::updatePrice(int tickerId, TickType field, double value)
{
	std::lock_guard<std::mutex> lock(mMutex);
	data[tickerId][field] = value;
}

void MarketDataStore::updateSize(int tickerId, TickType field, int size)
{
	std::lock_guard<std::mutex> lock(mMutex);
	data[tickerId][field] = static_cast<double>(size);
}

double MarketDataStore::getValue(int tickerId, TickType field) const
{
	std::lock_guard<std::mutex> lock(mMutex);
	
	auto it = data.find(tickerId);

	if(it!= data.end() && it -> second.count(field))
	{
		return it -> second.at(field);
	}

	return 0.0;
}