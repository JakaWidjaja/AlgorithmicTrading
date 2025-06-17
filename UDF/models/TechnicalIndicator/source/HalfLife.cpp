#include "HalfLife.h"
#include <stdexcept>
#include <vector>
#include <numeric>
#include <cmath>

using std::vector;
using std::invalid_argument;
using std::accumulate;
using std::log;

HalfLife::HalfLife()
{}

void HalfLife::compute(const vector<double>& data)
{
	if(data.size() < 2)
	{
		throw invalid_argument("Insufficient data for Half-Life calculation");
	}

	int n = data.size();
	vector<double> delta(n - 1);
	vector<double> lagged(n - 1);

	for(int i = 1; i < n; ++i)
	{
		delta[i - 1] = data[i] - data[i - 1];
		lagged[i - 1] = data[i - 1];
	}

	double lagMean = accumulate(lagged.begin(), lagged.end(), 0.0) / lagged.size();
	double deltaMean = accumulate(delta.begin(), delta.end(), 0.0) / delta.size();

	double num = 0.0;
	double den = 0.0;
	for(size_t i = 0; i < lagged.size(); ++i)
	{
		num += (lagged[i] - lagMean) * (delta[i] - deltaMean);
		den += (lagged[i] - lagMean) * (lagged[i] - lagMean);
	}

	if(den == 0.0)
	{
		throw invalid_argument("Zero variance in lagged data");
	}

	double beta = num / den;

	halfLife = -log(2) / beta;
}

double HalfLife::getValue() const
{
	return halfLife;
}