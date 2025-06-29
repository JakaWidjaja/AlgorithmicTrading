#include "PortfolioWeightsOH.h"
#include "SavitzkyGolay.h"
#include <nlopt.hpp>
#include <stdexcept>
#include <iostream>
#include <numeric>

using std::vector;
using std::string;
using std::invalid_argument;
using std::exception;
using std::cerr;
using std::accumulate;

PortfolioWeightsOH::PortfolioWeightsOH(int windowSize, int polyOrder) : ou(), windowSize(windowSize), polyOrder(polyOrder)
{}

vector<double> PortfolioWeightsOH::OH(const Eigen::MatrixXd& data, int numData,
									  const vector<double>& weights, const string& longShort)
{
	Eigen::MatrixXd timeSeries = data.bottomRows(numData);
	int numRows = timeSeries.rows();
	int numCols = timeSeries.cols();

	auto objective = [&](const vector<double>& w, vector<double>& grad)	
	{
		Eigen::VectorXd weightVec      = Eigen::Map<const Eigen::VectorXd>(w.data(), w.size());
		Eigen::VectorXd weightedSeries = timeSeries * weightVec;

		vector<double> series(weightedSeries.data(), weightedSeries.data() + weightedSeries.size());

		SavitzkyGolay sg(windowSize, polyOrder);
		sg.compute(series);
		vector<double> smoothedSeries = sg.getValue();

		auto [mu, theta, sigma] = ou.calibrate(smoothedSeries);
		/*
		if (smoothedSeries.empty() || !std::isfinite(theta) || !std::isfinite(sigma)) 
		{
			std::cerr << "Invalid OU calibration. theta: " << theta << ", sigma: " << sigma << "\n";
			return std::numeric_limits<double>::max(); // Penalize invalid solutions
		}
		*/
		double value = -(theta - sigma);
		/*
		std::cerr << "Objective called. theta = " << theta
		          << ", sigma = " << sigma
		          << ", value = " << value << "\n";
		*/
		return value;
	};

	vector<double> lb, ub;
	for(size_t i = 0; i < weights.size(); ++i)
	{
		if(longShort == "longshort")
		{
			lb.push_back(-0.99);
			ub.push_back(0.99);
		}
		else if(longShort == "long")
		{
			lb.push_back(0.0);
			ub.push_back(1.0);
		}
		else if(longShort == "short")
		{
			lb.push_back(-0.99);
			ub.push_back(0.0);
		}
		else
		{
			throw invalid_argument("Unknown longshort: " + longShort);
		}
	}

	vector<nlopt::algorithm> methods = 
	{
		nlopt::LN_COBYLA,
		nlopt::LD_SLSQP
	};

	vector<double> result(weights.size(), 0.0);
	double minf = 0.0;
	bool success = false;

	for(auto alg : methods)
	{
		try
		{
			nlopt::opt opt(alg, weights.size());
			opt.set_min_objective([](const vector<double>& x, vector<double>& grad, void* f_data)
			{return (*static_cast<decltype(objective)*>(f_data))(x, grad);}, &objective);

			opt.add_equality_constraint([](const vector<double>& x, vector<double>& grad, void* data)
				{return accumulate(x.begin(), x.end(), 0.0) - 1.0;}, nullptr);

			opt.set_lower_bounds(lb);
			opt.set_upper_bounds(ub);
			opt.set_xtol_rel(1e-4);

			vector<double> x(weights.size(), 1.0 / weights.size());
			//std::cerr << "Starting optimization with alg = " << alg << "\n";
			nlopt::result r = opt.optimize(x, minf);
			//std::cerr << "Finished with minf = " << minf << "\n";
			result = x;
			success = true;
			break;
		}
		catch (exception& e)
		{
			cerr << "NLopt " << alg << "failed: " << e.what() << "\n";
			continue;
		}
	}

	return success ? result : vector<double>(weights.size(), 0.0);
} 