#include "TrendSignal.h"
#include <iostream>

using std::string;
using std::vector;
using std::shared_ptr;
using std::abs;

TrendSignal::TrendSignal(const shared_ptr<ConfigModel>& modelConfig)
{
	stopLossPerc1  = modelConfig -> getStopLoss1();
	stopLossPerc2  = modelConfig -> getStopLoss2();
	profitLimit    = modelConfig -> getProfitLimit();	
	doubleSMAShort = modelConfig -> getDoubleSMAShortWindow();
	doubleSMALong  = modelConfig -> getDoubleSMALongWindow();
}

Eigen::MatrixXd TrendSignal::signal(double hurst,
									double varianceRatio,
									double halfLife,
									const DoubleSMA& sma,
									double lastPrice,
									const vector<string>& stockNames,
									const Eigen::MatrixXd& portfolioData) const
{
	Eigen::MatrixXd result;

	if(hurst >= 0.55 && varianceRatio > 1.0 && halfLife < 0.0)
	{
		vector<double> values = sma.getValue();
		if(values.empty()) return result;

		double diff = values.back();
		if(abs(diff) < 1.0) return result;

		bool isLong = diff > 0.0;
		int numStocks = static_cast<int>(stockNames.size());
		int cols = 3 + numStocks * 3 + 1;

		result.resize(1, cols);
		result.setZero();

		result(0, 0) = isLong ? 2.0 : 1.0; // direction
		result(0, 1) = lastPrice;

		for(int i = 0; i < numStocks; ++i)
		{
			result(0, 2 + i * 3)     = static_cast<double>(i);
			result(0, 2 + i * 3 + 1) = static_cast<double>(i);
			double stopMult = isLong ? (1.0 - stopLossPerc1) : (1.0 + stopLossPerc1);
			result(0, 2 + i * 3 + 2) = portfolioData(portfolioData.rows() - 1, i) * stopMult;
		}

		result(0, cols - 1) = lastPrice * (isLong ? (1.0 - stopLossPerc1) : (1.0 + stopLossPerc1));
	}

	return result;
}