#ifndef SINGLE_SMA_H
#define SINGLE_SMA_H

#include "TechnicalIndicators.h"
#include <vector>

class SingleSMA : public TechnicalIndicators
{
public:
	explicit SingleSMA(int window);
	void compute(const std::vector<double>& data) override;
	const std::vector<double>& getValue() const;

private:
	int window;
	std::vector<double> smaValues;
};

#endif