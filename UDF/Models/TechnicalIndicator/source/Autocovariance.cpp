#include "Autocovariance.h"

#include <numeric>
#include <stdexcept>
#include <vector>

using std::invalid_argument;
using std::vector;
using std::accumulate;

Autocovariance::Autocovariance(int lag): lag(lag), value(0.0)
{
	if(lag < 0)
	{
		throw invalid_argument("Lag value must be positive");
	}
}

void Autocovariance::compute(const vector<double>& data)
{
	if(data.size() <= static_cast<size_t>(lag))
	{
		throw invalid_argument("Data size must be greater than lag value");
	}

	size_t n = data.size();
	double mean = accumulate(data.begin(), data.end(), 0.0) / n;

	double cov = 0.0;
	for(size_t i = 0; i < n - lag; ++i)
	{
		cov += (data[i] - mean) * (data[i + lag] - mean);
	}

	value = cov / (n - lag);
}

double Autocovariance::getValue() const
{
	return value;
}