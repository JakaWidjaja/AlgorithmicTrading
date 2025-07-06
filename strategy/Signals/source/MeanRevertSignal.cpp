#include "MeanRevertSignal.h"
#include <iostream>

using std::string;
using std::vector;
using std::map;
using std::stod;
using std::shared_ptr;

MeanRevertSignal::MeanRevertSignal(const shared_ptr<Config>& modelConfig)
{
	stopLossPerc1 = modelConfig -> getStopLoss1();
	stopLossPerc2 = modelConfig -> getStopLoss2();
	profitLimit   = modelConfig -> getProfitLimit();	
}

Eigen::MatrixXd MeanRevertSignal::signal(double hurst, double halfLife, const SingleSMA& sma,
										 double mu, double sigma, double lastPrice,
										 const vector<string>& stockNames, const Eigen::MatrixXd& portfolioData) const
{
	Eigen::MatrixXd results;

	if(hurst < 0.40 && halfLife > 0.0 && halfLife < 100.0)
	{
		double smaLast = sma.getValue().back();
		bool conditionalShort = (lastPrice > mu) && (smaLast > mu + sigma * 5.0 || smaLast < mu - sigma * 5.0);
		bool conditionalLong  = (lastPrice < mu) && (smaLast < mu - sigma * 5.0 || smaLast > mu - sigma * 5.0);

		if (conditionShort || condition Long)
		{
			int numStocks = static_cast<int>(stockNames.size());
			int cols = 3 + numStocks * 3 + 1;
			result.resize(1, cols);
			result.setZero();

			result(0, 0) = conditionShort? 1.0 : 2.0;
			result(0, 1) = lastPrice;

			for(int i = 0; i < numStocks; ++i)
			{
				result(0, 2 + i * 3)     = static_cast<double>(i); // Placeholder for name index
				result(0, 2 + i * 3 + 1) = static_cast<double>(i); // Placeholder for num shares
				result(0, 2 + i * 3 + 2) = portfolioData(portfolioData.rows() - 1, i) * (1.0 = stopLossPerc1);
			}

			result(0, cols - 1) = lastPrice * (1.0 - stopLossPerc1); // Portfolio stop loss
		} 
	}
	return result;
}