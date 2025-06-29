#ifndef MEAN_REVERTING_PORTFOLIO_H
#define MEAN_REVERTING_PORTFOLIO_H

#include "PortfolioSelection.h"
#include <vector>
#include <string>
#include <Eigen/Dense>
#include <map>

struct portfolioRow
{
	std::vector<std::string> combination;
	std::vector<double> weights;
};

class MeanRevertingPortfolio
{
public:
	MeanRevertingPortfolio(int numTopStocks, int lengthTimeSeries);

	std::vector<std::vector<std::string>> stockSelection(const Eigen::MatrixXd& data, const std::vector<std::string> stockNames, 
														int numStockToUse, std::string highLow);

	std::vector<portfolioRow> portfolioPositions(const std::vector<std::vector<std::string>>& portfolioList,
												 const Eigen::MatrixXd& priceMatrix,
												 const std::vector<std::string>& stockNames,
												 const std::string& longShort);

private:
	int numTopStocks;
	int lengthTimeSeries;
	PortfolioSelection portSelection;

};

#endif