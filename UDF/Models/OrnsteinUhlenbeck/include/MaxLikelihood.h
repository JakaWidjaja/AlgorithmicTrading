#ifndef MAX_LIKELIHOOD_H
#define MAX_LIKELIHOOD_H

#include "OrnsteinUhlenbeck.h"

class MaxLikelihood : public OrnsteinUhlenbeck
{
public:
	MaxLikelihood();
	~MaxLikelihood() override;

	std::vector<double> calibrate(const std::vector<double>& timeSeries) const override;
};

#endif