#ifndef MEAN_REVERT_SIGNAL_H
#define MEAN_REVERT_SIGNAL_H

#include <string>
#include <vector>
#include <map>
#include <memory>
#include <Eigen/Dense>
#include "Config.h"
#include "SingelSMA.h"

class MeanRevertSignal
{
public:
	explicit MeanRevertSignal(const std::shared_ptr<Config>& modelConfig);

	Eigen::MatrixXd signal(double hurst, 
						   double halflife, 
						   const SingleSMA& sma,
						   double mu,
						   double sigma,
						   double lastPrice,
						   const std::vector<std::string>& stockNames,
						   const Eigen::MatrixXd& portfolioData) const;
private:
	double stopLossPerc1;
	double stopLossPerc2;
	double profitLimit;
};

#endif