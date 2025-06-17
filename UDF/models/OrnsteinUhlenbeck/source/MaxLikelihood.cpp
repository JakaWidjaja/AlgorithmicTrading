#include "MaxLikelihood.h"
#include <vector>
#include <cmath>
#include <numeric>
#include <stdexcept>

using std::vector;
using std::accumulate;
using std::log;
using std::exp;
using std::sqrt;

MaxLikelihood::MaxLikelihood() = default;
MaxLikelihood::~MaxLikelihood() = default;

vector<double> MaxLikelihood::calibrate(const vector<double>& timeSeries) const
{
	size_t n = timeSeries.size();
	if(n < 2)
	{
		throw std::invalid_argument("Time series must contain at least 2 data points.");
	}

	double timeDelta = 1.0 / static_cast<double>(n);

	double xx = accumulate(timeSeries.begin(), timeSeries.end() - 1, 0.0);
	double xy = accumulate(timeSeries.begin() + 1, timeSeries.end(), 0.0);

	double xxx = 0.0;
	double xxy = 0.0;
	double xyy = 0.0;
	for(size_t i = 1; i < n; ++i)
	{
		xxx += timeSeries[i - 1] * timeSeries[i - 1];
		xxy += timeSeries[i - 1] * timeSeries[i];
		xyy += timeSeries[i] * timeSeries[i];
	}

	// Theta
	double numerator = xy * xxx - xx * xxy;
	double denominator = static_cast<double>(n) * (xxx - xxy) - (xx * xx - xx * xy);
	double theta = numerator / denominator;

	// Mu
	double thetaSq = theta * theta;
	double muNumerator = xxy - theta * xx - theta * xy + static_cast<double>(n) * thetaSq;
	double muDenominator = xxx - 2.0 * theta * xx + static_cast<double>(n) * thetaSq;
	double mu = -1.0 / timeDelta * log(muNumerator / muDenominator);

	// Variance
	double expNegMuDt = exp(-mu * timeDelta);
	double expNeg2MuDt = exp(-2.0 * mu * timeDelta);
	double oneMinusExp = 1.0 - expNegMuDt;
	double oneMinusExp2 = 1.0 - expNeg2MuDt;

	double variance = (2.0 * mu / (n * oneMinusExp2)) *
        (xyy - 2.0 * expNegMuDt * xxy + expNeg2MuDt * xxx
        - 2.0 * theta * oneMinusExp * (xy - expNegMuDt * xx)
        + static_cast<double>(n) * thetaSq * oneMinusExp * oneMinusExp);

    // Sigma
    double sigma = variance * (2.0 * mu / oneMinusExp2);

    return {mu, theta, sigma};
}