#ifndef UTILITIES_H
#define UTILITIES_H

#include "Contract.h"
#include "MeanRevertingPortfolio.h" // for portfolioRow
#include <set>
#include <string>
#include <vector>
#include <map>
#include <chrono>
#include <ctime>
#include <sstream>
#include <iomanip>

class Utilities
{
public:
	// Data structure
	/*
	struct portfolioRow
	{
		std::vector<std::string> combinations;
		std::vector<double> weights;
	};
	*/
	Utilities();


	std::set<std::string> uniqueTickers(const std::vector<portfolioRow>& portWeights);
	std::vector<Contract> uniqueContracts(const std::vector<Contract>& contracts,
	                                      const std::set<std::string>& uniqueTickers);
	std::map<std::string, std::map<std::string, double>> filteredHistData(const std::set<std::string>& uniqueTickers,
																		  const std::map<std::string, std::map<std::string, double>>& histData);

	std::string TodayDate();


};

#endif
