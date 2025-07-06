#ifndef TECHNICALINDICATORS_H
#define TECHNICALINDICATORS_H

#include <vector>

class TechnicalIndicators
{
public:
	virtual ~TechnicalIndicators() = default; 

	virtual void compute(const std::vector<double>& data) = 0;
};

#endif