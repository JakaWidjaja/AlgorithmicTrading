#ifndef PORTFOLIO_SELECTION_H
#define PORTFOLIO_SELECTION_H

#include <Eigen/Dense>
#include <vector>
#include <string>
#include <map>

class PortfolioSelection
{
public:
	PortfolioSelection();
	virtual ~PortfolioSelection() = default;

	std::vector<std::string> PCA(const Eigen::MatrixXd& priceData,
								 const std::vector<std::string>& stockNames,
								 int numData, int numStocks, const std::string& highLow);

	static void reshapePriceMatrixData(const std::map<std::string, std::map<std::string, double>>& priceMap,
									   Eigen::MatrixXd& priceMatrix, 
									   std::vector<std::string>& dateList, 
									   std::vector<std::string>& stockList);
private:
	Eigen::MatrixXd computeReturns(const Eigen::MatrixXd& priceData);
	Eigen::MatrixXd standardised(const Eigen::MatrixXd& returns);
};

#endif