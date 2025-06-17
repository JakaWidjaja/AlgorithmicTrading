#include "DoubleSMA.h"

#include <numeric>
#include <stdexcept>

using std::invalid_argument;
using std::accumulate;
using std::vector;

DoubleSMA::DoubleSMA(int shortWindow, int longWindow) : shortWindow(shortWindow), longWindow(longWindow)
{
	if(shortWindow <= 0)
	{
		throw invalid_argument("Short Window has to be positive");
	}

	if(longWindow <= 0)
	{
		throw invalid_argument("Long Window has to be positive");
	}

	if(shortWindow >= longWindow)
	{
		throw invalid_argument("Short window has to be smaller than long window");
	}
}

vector<double> DoubleSMA::simpleMovingAverage(const vector<double>& data, int window)
{
	vector<double> sma;
	if(data.size() < static_cast<size_t>(window))
	{
		return sma;
	}

	double sum = accumulate(data.begin(), data.begin() + window, 0.0);
	sma.push_back(sum/window);

	for(size_t i = window; i < data.size(); ++i)
	{
		sum += data[i] - data[i - window];
		sma.push_back(sum/window);
	}

	return sma;
}

void DoubleSMA::compute(const vector<double>& data)
{
	auto smaShort = simpleMovingAverage(data, shortWindow);
	auto smaLong  = simpleMovingAverage(data, longWindow);

	doubleSMA.clear();
	for(size_t i = 0; i < smaLong.size(); ++i)
	{
		doubleSMA.push_back(smaShort[i + (longWindow - shortWindow)] - smaLong[i]);
	}
}

vector<double> DoubleSMA::getValue() const
{
	return doubleSMA;
}