#ifndef HURST_EXPONENT_H
#define HURST_EXPONENT_H

#include "TechnicalIndicators.h"
#include <vector>

class HurstExponent : public TechnicalIndicators
{
public:
	HurstExponent();
	void compute(const std::vector<double>& data) override;
	double getValue() const;

private:
	double hurst = 0.0;
};

#endif