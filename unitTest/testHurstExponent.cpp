#include "HurstExponent.h"
#include <gtest/gtest.h>
#include <vector> 
#include <cmath>
#include <stdexcept>

using std::vector;
using std::fabs;
using std::invalid_argument;

bool approxEqual(double a, double b, double tol = 1e-3) {
    return std::fabs(a - b) < tol;
}

TEST(HurstExponentTest, RegularData) 
{
    vector<double> data(100);
    for (int i = 0; i < 100; ++i) {
        data[i] = static_cast<double>(i);
    }

    HurstExponent hurst;
    hurst.compute(data);

    double value = hurst.getValue();
    EXPECT_TRUE(value > 0.0 && value < 1.0); 
}

TEST(HurstExponentTest, SmallDataThrows) 
{
    vector<double> data(10, 1.0);
    HurstExponent hurst;
    EXPECT_THROW(hurst.compute(data), std::invalid_argument);
}

TEST(HurstExponentTest, ConstantSeriesThrows) {

    vector<double> data(100, 5.0);
    HurstExponent hurst;
    EXPECT_THROW(hurst.compute(data), std::invalid_argument);
}

int main(int argc, char **argv) 
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}