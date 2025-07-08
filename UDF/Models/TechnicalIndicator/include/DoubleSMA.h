#ifndef DOUBLE_SMA_H
#define DOUBLE_SMA_H

#include "TechnicalIndicators.h"
#include <vector>

class DoubleSMA : public TechnicalIndicators
{
public:
	DoubleSMA(int shortWindow, int longWindow);
	~DoubleSMA() = default;

	void compute(const std::vector<double>& data) override;
	std::vector<double> getValue() const;

private:
	int shortWindow;
	int longWindow;
	std::vector<double> doubleSMA;
	std::vector<double> simpleMovingAverage(const std::vector<double>& data, int window);

};

#endif