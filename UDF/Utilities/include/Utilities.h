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
#include <Eigen/Dense>

class Utilities
{
public:
	Utilities();


	std::set<std::string> uniqueTickers(const std::vector<portfolioRow>& portWeights);
	std::vector<Contract> uniqueContracts(const std::vector<Contract>& contracts,
	                                      const std::set<std::string>& uniqueTickers);
	std::map<std::string, std::map<std::string, double>> filteredHistData(const std::set<std::string>& uniqueTickers,
																		  const std::map<std::string, std::map<std::string, double>>& histData);

	std::string TodayDate();

	void exportFilteredHistDataToCSV(const std::string& filepath,
									 const std::map<std::string, std::map<std::string, double>>& data) const;

	void exportMatrixToCSV(const std::string& filePath,
						   const Eigen::MatrixXd& matrix, 
						   const std::vector<std::string>& rowLabels, 
						   const std::vector<std::string>& colLabels) const;

	void exportListToCSV(const std::string& filePath,
						 const std::vector<std::string>& data,
						 const std::string& header) const;

};

#endif
