#ifndef ORNSTEIN_UHLENBECK
#define ORNSTEIN_UHLENBECK

#include <vector>

class OrnsteinUhlenbeck
{
public:
	OrnsteinUhlenbeck() = default;
	virtual ~OrnsteinUhlenbeck() = default;

	virtual std::vector<double> calibrate(const std::vector<double>& timeSeries) const = 0;

private:

};

#endif