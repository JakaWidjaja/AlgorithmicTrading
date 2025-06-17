#include "SingleSMA.h"
#include <stdexcept>
#include <numeric>
#include <vector>

using std::invalid_argument;
using std::vector;
using std::accumulate;

SingleSMA::SingleSMA(int window) : window(window)
{
	if(window <= 0)
	{
		throw invalid_argument("Window size must be positive");
	}
}

void SingleSMA::compute(const vector<double>& data)
{
	smaValues.clear();

	if(static_cast<int>(data.size()) < window)
	{
		throw invalid_argument("Insufficient data for calculation");
	}

	double sum = accumulate(data.begin(), data.begin() + window, 0.0);
	smaValues.push_back(sum / window);

	for(size_t i = window; i < data.size(); ++i)
	{
		sum += data[i] - data[i - window];
		smaValues.push_back(sum / window);
	}

}

const vector<double>& SingleSMA::getValue() const
{
	return smaValues;
}
