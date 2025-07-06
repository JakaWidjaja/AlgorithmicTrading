#include "Utilities.h"
#include <iostream>

using std::set;
using std::string;
using std::map;
using std::vector;
using std::time_t;
using std::ostringstream;
using std::put_time;
using std::localtime;

Utilities::Utilities() {}

set<string> Utilities::uniqueTickers(const vector<portfolioRow>& portWeights)
{
	set<string> unique;
	for (const auto& row : portWeights) 
	{
		for (const auto& symbol : row.combination) 
		{
			unique.insert(symbol);
		}
	}
	return unique;
}

vector<Contract> Utilities::uniqueContracts(const vector<Contract>& contracts, const set<string>& uniqueTickers)
{
	vector<Contract> unique;
	for (const auto& c : contracts) 
	{
		if (uniqueTickers.count(c.symbol)) 
		{
			unique.push_back(c);
		}
	}
	return unique;
}

map<string, map<string, double>> Utilities::filteredHistData(const set<string>& uniqueTickers,
															 const map<string, map<string, double>>& histData)
{
	map<string, map<string, double>> filtered;
	for (const auto& [date, priceMap] : histData) 
	{
		map<string, double> filteredPrices;
		for (const auto& symbol : uniqueTickers) 
		{
			auto it = priceMap.find(symbol);
			if (it != priceMap.end()) 
			{
				filteredPrices[symbol] = it->second;
			}
		}
		if (!filteredPrices.empty()) 
		{
			filtered[date] = filteredPrices;
		}
	}
	return filtered;
}

string Utilities::TodayDate()
{
	auto now = std::chrono::system_clock::now();
	time_t t = std::chrono::system_clock::to_time_t(now);
	ostringstream oss;
	oss << put_time(localtime(&t), "%Y%m%d");
	return oss.str();
}
