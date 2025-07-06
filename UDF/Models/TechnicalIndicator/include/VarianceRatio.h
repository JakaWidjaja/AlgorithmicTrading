#ifndef VARIANCE_RATIO_H
#define VARIANCE_RATIO_H

#include "TechnicalIndicators.h"
#include <vector>

class VarianceRatio : public TechnicalIndicators
{
public:
	VarianceRatio(int lag = 2);
	void compute(const std::vector<double>& data) override;
	double getValue() const;
	int getLag() const;
	void setLag(int newLag);

private:
	int lag;
	double vr = 0.0;
};

#endif