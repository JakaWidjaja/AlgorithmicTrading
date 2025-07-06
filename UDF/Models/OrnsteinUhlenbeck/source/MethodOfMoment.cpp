#include "MethodOfMoment.h"
#include <vector>
#include <cmath>
#include <numeric>
#include <stdexcept>
#include <tuple>

using std::vector;
using std::accumulate;
using std::log;
using std::sqrt;
using std::make_tuple;
using std::tuple;

MethodOfMoment::MethodOfMoment() = default;

MethodOfMoment::~MethodOfMoment() = default;

tuple<double, double, double> MethodOfMoment::calibrate(const vector<double>& timeSeries) const
{
	size_t n = timeSeries.size();
	if(n < 2)
	{
		throw std::invalid_argument("Time series must contain at least 2 data points.");
	}

	// m1
	double sum = accumulate(timeSeries.begin(), timeSeries.end(), 0.0);
	double m1 = sum / (n + 1.0);

	// m2
	double m2 = 0.0;
	for(const auto& x : timeSeries)
	{
		m2 += (x - m1) * (x - m1);
	}
	m2 /= static_cast<double>(n);

	// m3
	double m3 = 0.0;
	for(size_t i = 1; i < n; ++i)
	{
		m3 += (timeSeries[i] - m1) * (timeSeries[i - 1] - m1);
	}
	m3 /= static_cast<double>(n - 1);

	// Theta
	double theta = n * log(m2 / m3);

	// Variance
	double variance = 2.0 * n * m2 * log(m2 / m3);

	// sigma
	double sigma = sqrt(variance);

	return make_tuple(m1, theta, sigma);
}