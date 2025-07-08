#ifndef GENERATE_SIGNALS_H
#define GENERATE_SIGNALS_H

#include <string>
#include <vector>
#include <map>
#include <memory>
#include <Eigen/Dense>

#include "ConfigModel.h"
#include "HalfLife.h"
#include "HurstExponent.h"
#include "VarianceRatio.h"
#include "SingleSMA.h"
#include "DoubleSMA.h"
#include "MethodOfMoment.h"
#include "SavitzkyGolay.h"
#include "MeanRevertSignal.h"
#include "MeanRevertingPortfolio.h" 
#include "TrendSignal.h"
/*
struct portfolioRow
{
    std::vector<std::string> stockNames;
    std::vector<double> weights;
};
*/
class GenerateSignals
{
public:
	GenerateSignals(const std::shared_ptr<ConfigModel>& modelConfig, 
				    const std::shared_ptr<HurstExponent>& hurst, 
				    const std::shared_ptr<VarianceRatio>& vr, 
				    const std::shared_ptr<HalfLife>& hl, 
				    const std::shared_ptr<SingleSMA>& singleSMA, 
				    const std::shared_ptr<SavitzkyGolay>& smoother, 
				    const std::vector<portfolioRow>& portfolios, 
				    double investAmt);

	std::pair<Eigen::MatrixXd, Eigen::MatrixXd> signals(const Eigen::MatrixXd& data);

private:
	std::shared_ptr<HurstExponent> hurstExp;
	std::shared_ptr<VarianceRatio> vRatio;
	std::shared_ptr<HalfLife> hlife;
	std::shared_ptr<SingleSMA> sma;
	std::shared_ptr<SavitzkyGolay> smoother;
	std::shared_ptr<MeanRevertSignal> meanRevert;
	std::shared_ptr<TrendSignal> trend;
	std::shared_ptr<MethodOfMoment> ou;
	std::vector<portfolioRow> portfolios;
	double investAmt;

	Eigen::MatrixXd meanRevertStrategy;
	Eigen::MatrixXd trendStrategy;

	int doubleSMAShort;
	int doubleSMALong;
};

#endif