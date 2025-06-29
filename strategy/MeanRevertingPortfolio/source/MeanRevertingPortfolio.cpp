#include "MeanRevertingPortfolio.h"
#include "PortfolioWeightsOH.h"
#include "Combinations.h"
#include <Eigen/Dense>
#include <vector>
#include <string>
#include <stdexcept>
#include <numeric>

using std::vector;
using std::string;
using std::invalid_argument;
using std::accumulate;
using std::map;
using std::distance;

MeanRevertingPortfolio::MeanRevertingPortfolio(int numTopStocks, int lengthTimeSeries) :
	numTopStocks(numTopStocks), lengthTimeSeries(lengthTimeSeries)
{}

vector<vector<string>> MeanRevertingPortfolio::stockSelection(const Eigen::MatrixXd& data, 
															  const vector<string> stockNames, 
															  int numStockToUse, string highLow)
{	
	// Select the top stocks
	// Use PCA to select the highsest or lowest variance
	PortfolioSelection portSelect;
	vector<string> topStocks = portSelect.PCA(data, stockNames, lengthTimeSeries, numTopStocks, highLow);

	// Calculate the different stock combinations
	Combinations stockComb;
	vector<vector<string>> stockCombinations = stockComb.generate(topStocks, numStockToUse);

	return stockCombinations;
}

vector<portfolioRow> MeanRevertingPortfolio::portfolioPositions(const vector<vector<string>>& portfolioList,
																const Eigen::MatrixXd& priceMatrix,
																const vector<string>& stockNames, 
																const string& longShort)
{
	vector<portfolioRow> results;
	PortfolioWeightsOH portWeight(31, 10);

	for(const auto& combination : portfolioList)
	{
		int numStock = combination.size();
		Eigen::MatrixXd stockMatrix(lengthTimeSeries, numStock);

		for(int col = 0; col < numStock; ++col)
		{
			const string& stock = combination[col];
			auto it = find(stockNames.begin(), stockNames.end(), stock);
			if(it == stockNames.end())
			{
				throw invalid_argument("Stock not found in stockNames: " + stock);
			}

			int index = distance(stockNames.begin(), it);
			if(priceMatrix.rows() < lengthTimeSeries || index >= priceMatrix.cols())
			{
				throw invalid_argument("Insufficient data for stock: " + stock);
			}

			for(int row = 0; row < lengthTimeSeries; ++row)
			{
				stockMatrix(row, col) = priceMatrix(row, index);
			}
		}

		vector<double> initialWeights(numStock, 0.5);
		vector<double> resultWeights = portWeight.OH(stockMatrix, lengthTimeSeries, initialWeights, longShort);
		
		double total = accumulate(resultWeights.begin(), resultWeights.end(), 0.0);
		if(total == 0.0) continue;

		results.push_back(portfolioRow{combination, resultWeights});
	}

	return results;
}