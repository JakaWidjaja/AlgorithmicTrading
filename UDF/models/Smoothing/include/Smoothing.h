#ifndef SMOOTHING_H
#define SMOOTHING_H

#include <vector>

class Smoothing
{
public:
	virtual ~Smoothing() = default;
	virtual void compute(const std::vector<double>& data) = 0;
	virtual std::vector<double> getValue() const = 0;
};

#endif