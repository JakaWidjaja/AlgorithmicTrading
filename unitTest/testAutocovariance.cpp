#include "Autocovariance.h"
#include <gtest/gtest.h>
#include <vector>
#include <cmath>
#include <stdexcept>

using std::vector;
using std::fabs;
using std::invalid_argument;

bool almostEqual(double a, double b, double epsilon = 1e-6)
{
	return fabs(a - b) < epsilon;
}

TEST(AutocovarianceTest, RegularDataLag1)
{
	vector<double> data = {1, 2, 3, 4, 5};
	Autocovariance cov(1);
	cov.compute(data);
	double expected = ((1 - 3)*(2 - 3) + (2 - 3)*(3 - 3) + (3 - 3)*(4 - 3) + (4 - 3)*(5 - 3)) / 4.0;
	EXPECT_TRUE(almostEqual(cov.getValue(), expected));
}

TEST(AutocovarianceTest, ConstantData)
{
	vector<double> data = {5, 5, 5, 5, 5};
	Autocovariance cov(2);
	cov.compute(data);
	EXPECT_DOUBLE_EQ(cov.getValue(), 0.0);
}

TEST(AutocovarianceTest, InvalidLagTooLarge)
{
	vector<double> data = {1,2};
	Autocovariance cov(3);
	EXPECT_THROW(cov.compute(data), invalid_argument);
}

TEST(Autocovariance, NegativeLag)
{
	EXPECT_THROW(Autocovariance(-1), invalid_argument);
}

int main(int argc, char **argv)
{
	::testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}