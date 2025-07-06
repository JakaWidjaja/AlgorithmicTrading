#ifndef TREND_SIGNAL_H
#define TREND_SIGNAL_H

#include "Config.h"
#include "DoubleSMA.h"
#include <string> 
#include <vector>
#include <memory>
#include <Eigen/Dense>

class TrendSignal
{
public:
	explicit TrendSignal(const std::shared_ptr<Config>& config);

	Eigen::MatrixXd signal(double hurst, class
						   double varianceRatio,
						   double halfLife,
						   const DoubleSMA& doubleSMA,
						   double lastPrice,
						   const std::vector<std:;string>& stockNames,
						   const Eigen::MatrixXd& portfolioData) const;
private:
	double stopLossPerc1;
	double stopLossPerc2;
	double profitLimit;
	double doubleSMAShort;
	double doubleSMALong;
};

#endif