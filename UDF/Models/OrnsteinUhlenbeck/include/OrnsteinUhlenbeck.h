#ifndef ORNSTEIN_UHLENBECK
#define ORNSTEIN_UHLENBECK

#include <tuple>
#include <vector>

class OrnsteinUhlenbeck
{
public:
	OrnsteinUhlenbeck() = default;
	virtual ~OrnsteinUhlenbeck() = default;

	virtual std::tuple<double, double, double> calibrate(const std::vector<double>& timeSeries) const = 0;

private:

};

#endif