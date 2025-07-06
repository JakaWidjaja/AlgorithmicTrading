#ifndef SAVITZKYGOLAY_H
#define SAVITZKYGOLAY_H

#include "Smoothing.h"
#include <vector>

class SavitzkyGolay : public Smoothing
{
public:
	SavitzkyGolay(int windowSize, int polyOrder);
	void compute(const std::vector<double>& data) override;
	std::vector<double> getValue() const override;

private:
	int windowSize;
	int polyOrder;
	std::vector<double> smoothed;
	std::vector<double> computeCoefficients() const;
};

#endif