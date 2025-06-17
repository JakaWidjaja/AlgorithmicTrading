#include "HurstExponent.h"
#include <vector>
#include <cmath>
#include <numeric>
#include <stdexcept>
#include <algorithm>

using std::vector;
using std::accumulate;
using std::invalid_argument;
using std::log;
using std::sqrt;

HurstExponent::HurstExponent()
{}

void HurstExponent::compute(const vector<double>& data)
{
	if(data.size() < 20)
	{
		throw invalid_argument("Insufficient data for Hurst Exponent calculation");
	}

	int n = data.size();
	vector<double> meanAdjusted(n);
	double mean = accumulate(data.begin(), data.end(), 0.0) / n;

	for(int i = 0; i < n; ++i)
	{
		meanAdjusted[i] = data[i] - mean;
	}

	vector<double> cumulative(n);
	cumulative[0] = meanAdjusted[0];
	for(int i = 1; i < n; ++i)
	{
		cumulative[i] = cumulative[i - 1] + meanAdjusted[i];
	}

	double range = *max_element(cumulative.begin(), cumulative.end()) - *min_element(cumulative.begin(), cumulative.end());
	double stdev = sqrt(accumulate(meanAdjusted.begin(), meanAdjusted.end(), 0.0, [](double sum, double val){return sum + val * val;}) / n);

	if (stdev == 0.0)
        throw invalid_argument("Standard deviation is zero, can't compute Hurst exponent");

    double rs = range / stdev;

    hurst = log(rs) / log(n * 1.0);
}

double HurstExponent::getValue() const
{
    return hurst;
}