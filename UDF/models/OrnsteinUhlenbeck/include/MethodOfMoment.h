#ifndef METHOD_OF_MOMENT_H
#define METHOD_OF_MOMENT_H

#include "OrnsteinUhlenbeck.h"

#include <vector>

class MethodOfMoment : public OrnsteinUhlenbeck
{
public:
	MethodOfMoment();
	~MethodOfMoment() override;

	std::vector<double> calibrate(const std::vector<double>& timeSeries) const override;

private:

};

#endif