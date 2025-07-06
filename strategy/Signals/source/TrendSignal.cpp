#include "TrendSignal.h"
#include <iostream>

using std::string;
using std::vector;
using std::shared_ptr;
using std::abs;

TrendSignal::TrendSignal(const shared_ptr<Config>& config)
{
	stopLossPerc1  = modelConfig -> getStopLoss1();
	stopLossPerc2  = modelConfig -> getStopLoss2();
	profitLimit    = modelConfig -> getProfitLimit();	
	doubleSMAShort = modelConfig -> getdoubleSMAShortWindow();
	doubleSMALong  = modelConfig -> getdoubleSMALongWindow();
}

Eigen::MatrixXd TrendSignal::signal(double hurst,
									double varianceRatio,
									double halfLife,
									const SingleSMA& sma,
									double lastPrice,
									const vector<string>& stockNames,
									const Eigen::MatrixXd& protfolioData) const
{
	Eigen::MatrixXd result;

	if(hurst >= 0.55 && varianceRatio > 1.0 && halfLife < 0.0)
	{
		vector<double> values = doubleSMA.getValue();
		if(value.size() < 2) return result;
	}
}