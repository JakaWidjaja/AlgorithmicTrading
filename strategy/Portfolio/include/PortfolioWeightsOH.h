#ifndef PORTFOLIOWEIGHTSOH_H
#define PORTFOLIOWEIGHTSOH_H

#include <Eigen/Dense>
#include <vector>
#include <string>
#include "MethodOfMoment.h"

class PortfolioWeightsOH
{
public:
	PortfolioWeightsOH(int windowSize = 30, int polyOrder = 10);
	std::vector<double> OH(const Eigen::MatrixXd& data,
						   int numData,
						   const std::vector<double>& weights, 
						   const std::string& longShort);
private:
	MethodOfMoment ou;
	int windowSize;
	int polyOrder;
};

#endif