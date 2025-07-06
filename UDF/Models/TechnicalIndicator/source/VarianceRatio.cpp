#include "VarianceRatio.h"
#include <cmath>
#include <numeric>
#include <stdexcept>
#include <vector>

using std::vector;
using std::invalid_argument;
using std::accumulate;

VarianceRatio::VarianceRatio(int lag) : lag(lag)
{
	if(lag <= 1)
	{
		throw invalid_argument("Lag must be greater than 1");
	}
}

void VarianceRatio::compute(const vector<double>& data)
{
	if(data.size() <= static_cast<size_t>(lag))
	{
		throw invalid_argument("Insufficient data");
	}

	size_t n = data.size();
	double mean = accumulate(data.begin() + 1, data.end(), 0.0) - accumulate(data.begin(), data.end() - 1, 0.0);
	mean /= (n - 1);

	// Single period variance
	double var1 = 0.0;
	for(size_t i = 1; i < n; ++i)
	{
		double diff = data[i] - data[i - 1] - mean;
		var1 += diff * diff;
	}
	var1 /= (n-1);

	// k-period variance
	double vark = 0.0;
	for(size_t i = lag; i < n; ++i)
	{
		double diff = data[i] - data[i - lag] - lag * mean;
		vark += diff * diff;
	}
	vark /= (n - lag);

	vr = vark / (lag * var1);
}

double VarianceRatio::getValue() const
{
	return vr;
}

int VarianceRatio::getLag() const
{
	return lag;
}

void VarianceRatio::setLag(int newLag)
{
	if(newLag <= 1)
	{
		throw invalid_argument("Lag must be greater than 1");
	}
	lag = newLag;
}
