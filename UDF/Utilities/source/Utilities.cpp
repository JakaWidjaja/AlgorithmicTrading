#include "Utilities.h"
#include <iostream>
#include <fstream>

using std::set;
using std::string;
using std::map;
using std::vector;
using std::time_t;
using std::ostringstream;
using std::put_time;
using std::localtime;
using std::ofstream;

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

void Utilities::exportFilteredHistDataToCSV(const string& filePath, const map<string, map<string, double>>& data) const
{
	if(data.empty()) return;

	ofstream file(filePath);
	if(!file.is_open()) return;

	// Header
	const auto& firstRow = data.begin() -> second;
	file << "Date";

	for(const auto& [symbol, _] : firstRow)
	{
		file << "," << symbol;
	}
	file <<"\n";

	// Rows
	for(const auto& [date, row] : data)
	{
		file << date;
		for(const auto& [symbol, _] : firstRow)
		{
			auto it = row.find(symbol);
			if(it != row.end())
			{
				file << "," << it -> second;
			}
			else
			{
				file << ",";
			}
		}
		file << "\n";
	}
	file.close();
}

void Utilities:: exportMatrixToCSV(const string& filePath,
								   const Eigen::MatrixXd& matrix,
								   const vector<string>& rowLabels,
								   const vector<string>& colLabels) const
{
	ofstream file(filePath);
	if(!file.is_open()) return;

	// Header
	file << "date";
	for(const auto& label : colLabels)
	{
		file << "," << label;
	}
	file << "\n";

	// Row
	for(int i = 0; i < matrix.rows(); ++i)
	{
		file << rowLabels[i];
		for(int j = 0; j < matrix.cols(); ++j)
		{
			file << "," << matrix(i, j);
		}
		file << "\n";
	}
	file.close();
}

void Utilities::exportListToCSV(const string& filePath,
								const vector<string>& data,
								const string& header) const
{
	ofstream file(filePath);
	if(!file.is_open()) return;

	file << header << "\n";
	for(const auto& item : data)
	{
		file << item << "\n";
	}
	file.close();
}

