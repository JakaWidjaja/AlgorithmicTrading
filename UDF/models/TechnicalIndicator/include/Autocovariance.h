#ifndef AUTOCOVARIANCE_H
#define AUTOCOVARIANCE_H

#include "TechnicalIndicators.h"

#include <vector>

class Autocovariance : public TechnicalIndicators
{
public:
	Autocovariance(int lag);
	void compute(const std::vector<double>& data) override;
	double getValue() const;

private:
	int lag;
	double value;
};

#endif