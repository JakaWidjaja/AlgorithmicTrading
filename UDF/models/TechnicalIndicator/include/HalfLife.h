#ifndef HALFLIFE_H
#define HALFLIFE_H

#include "TechnicalIndicators.h"
#include <vector>

class HalfLife : public TechnicalIndicators
{
public:
	HalfLife();
	void compute(const std::vector<double>& data) override;
	double getValue() const;

private:
	double halfLife = 0.0;
};

#endif