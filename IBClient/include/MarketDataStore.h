#ifndef MARKETDATASTORE_H
#define MARKETDATASTORE_H

#include <unordered_map>
#include <mutex>
#include "EWrapper.h"

class MarketDataStore
{
public:
	MarketDataStore();
	~MarketDataStore(); 
	
	void updatePrice(int tickerId, TickType field, double value);
	void updateSize(int tickerId, TickType field, int size);
	double getValue(int tickerId, TickType field) const;

private:
	mutable std::mutex mMutex;
	std::unordered_map<int, std::unordered_map<TickType, double>> data;
};

#endif