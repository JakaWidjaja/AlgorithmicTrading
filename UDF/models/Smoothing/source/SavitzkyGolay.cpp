#include "SavitzkyGolay.h"
#include <stdexcept>
#include <vector>
#include <Eigen/Dense>
#include <cmath>

using std::vector;
using std::invalid_argument;
using Eigen::MatrixXd;
using Eigen::VectorXd;
using std::pow;

SavitzkyGolay::SavitzkyGolay(int windowSize, int polyOrder) : windowSize(windowSize), polyOrder(polyOrder)
{
	if(windowSize % 2 == 0 || windowSize < 1)
	{
		throw invalid_argument("Window size must be a positive odd number");
	}

	if(polyOrder >= windowSize)
	{
		throw invalid_argument("Polynomial order must be less than window size");
	}
}	

vector<double> SavitzkyGolay::computeCoefficients() const
{
	int m = windowSize;
	int n = polyOrder;

	MatrixXd A(m, n + 1);
	int half = m / 2;

	// Vandermonde matrix A
	for(int i = -half; i <= half; ++i)
	{
		for(int j = 0; j <= n; ++j)
		{
			A(i + half, j) = pow(i, j);
		}
	} 

	// Compute (A^T A)^(-1) A^T
	MatrixXd ATA = A.transpose() * A;
	MatrixXd ATAInv = ATA.inverse();
	MatrixXd B = ATAInv * A.transpose();

	// Coefficient for smoothing (0-th derivative at center)
	vector<double> coeffs(m);
	for(int i = 0; i < m; ++i)
	{
		coeffs[i] = B.row(0)(i);
	}

	return coeffs;
}

void SavitzkyGolay::compute(const vector<double>& data)
{
	if(data.size() < static_cast<size_t>(windowSize))
	{
		throw invalid_argument("Insufficient data for Savitzky-Golay smoothing");
	}

	smoothed.clear();
	vector<double> coeffs = computeCoefficients();
	int halfWindow = windowSize / 2;

	for(size_t i = 0; i < data.size(); ++i)
	{
		double sum = 0.0;
		for(int j = -halfWindow; j <= halfWindow; ++j)
		{
			int k = static_cast<int>(i) + j;
			if(k < 0)
			{
				k = -k;
			}
			else if(k >= static_cast<int>(data.size()))
			{
				k = 2 * static_cast<int>(data.size()) - k - 2;
			}
			sum += coeffs[j + halfWindow] * data[k];
		}
		smoothed.push_back(sum);
	}
}

vector<double> SavitzkyGolay::getValue() const
{
	return smoothed;
}