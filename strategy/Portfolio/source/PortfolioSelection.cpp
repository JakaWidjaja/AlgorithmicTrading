#include "PortfolioSelection.h"
#include <algorithm>
#include <numeric>
#include <cmath>
#include <stdexcept>
#include <set>

using std::string;
using std::vector;
using std::map;
using std::set;
using std::pair;
using std::invalid_argument;
using std::partial_sort;

PortfolioSelection::PortfolioSelection()
{}

Eigen::MatrixXd PortfolioSelection::computeReturns(const Eigen::MatrixXd& priceData)
{
	int rows = priceData.rows();
	int cols = priceData.cols();
	Eigen::MatrixXd returns(rows - 1, cols);
	for(int i = 1; i < rows; ++i)
	{
		for(int j = 0; j < cols; ++j)
		{
			double prev = priceData(i - 1, j);
			double curr = priceData(i, j);
			returns(i - 1, j) = (prev != 0.0) ? (curr - prev) / prev : 0.0;
		}
	}
	return returns;
}

Eigen::MatrixXd PortfolioSelection::standardised(const Eigen::MatrixXd& returns)
{
	int rows = returns.rows();
	int cols = returns.cols();
	Eigen::MatrixXd standard = returns;

	for(int j = 0; j < cols; ++j)
	{
		Eigen::VectorXd col = returns.col(j);
		double mean = col.mean();
		double stdev = std::sqrt((col.array() - mean).square().sum() / (rows - 1));

		if(stdev == 0.0)
		{
			standard.col(j).setZero();
		}
		else
		{
			standard.col(j) = (col.array() - mean) / stdev;
		}
	}
	return standard;
}

vector<string> PortfolioSelection::PCA(const Eigen::MatrixXd& priceData, const vector<string>& stockNames, 
										int numData, int numStocks, const string& highLow)
{
	if(priceData.rows() < numData +1)
	{
		throw invalid_argument("Not enough rows in priceData");
	}

	Eigen::MatrixXd recentPrice = priceData.bottomRows(numData);
	Eigen::MatrixXd returns     = computeReturns(recentPrice);
	Eigen::MatrixXd standard    = standardised(returns);

	Eigen::JacobiSVD<Eigen::MatrixXd> svd(standard, Eigen::ComputeThinU | Eigen::ComputeThinV);
	Eigen::MatrixXd components = svd.matrixV();

	Eigen::VectorXd contribution = components.cwiseAbs().rowwise().sum();

	vector<pair<string, double>> stockScores;
	for(size_t i = 0; i < stockNames.size(); ++i)
	{
		stockScores.emplace_back(stockNames[i], contribution(i));
	}

	if(highLow == "high" || highLow == "HIGH")
	{
		partial_sort(stockScores.begin(), stockScores.begin() + numStocks, stockScores.end(), 
					[](const auto& a, const auto& b) {return a.second > b.second;});
	}
	else
	{
		partial_sort(stockScores.begin(), stockScores.begin() + numStocks, stockScores.end(), 
					[](const auto& a, const auto& b) {return a.second < b.second;});
	}

	vector<string> topStocks;
	for(int i = 0; i < numStocks; ++i)
	{
		topStocks.push_back(stockScores[i].first);
	}

	return topStocks;
}

void PortfolioSelection::reshapePriceMatrixData(const map<string, map<string, double>>& priceMap, 
												Eigen::MatrixXd& priceMatrix, 
												vector<string>& dateList,
												vector<string>& stockList)
{
	set<string> uniqueDates;
	set<string> uniqueStocks;

	for(const auto& [date, stocks] : priceMap)
	{
		uniqueDates.insert(date);
		for(const auto& [stock, _] : stocks)
		{
			uniqueStocks.insert(stock);
		}
	}

	dateList.assign(uniqueDates.begin(), uniqueDates.end());
	stockList.assign(uniqueStocks.begin(), uniqueStocks.end());

	int rows = dateList.size();
	int cols = stockList.size();
	priceMatrix = Eigen::MatrixXd::Zero(rows, cols);

	for(int i = 0; i < rows; ++i)
	{
		const string& date = dateList[i];
		for(int j = 0; j < cols; ++j)
		{
			const string& stock = stockList[j];
			if(priceMap.count(date) && priceMap.at(date).count(stock))
			{
				priceMatrix(i, j) = priceMap.at(date).at(stock);
			}
			else
			{
				priceMatrix(i, j) = 0.0;
			}
		}
	}
}