#include "MethodOfMoment.h"
#include <gtest/gtest.h>
#include <vector>
#include <stdexcept>
#include <cmath>
#include <random>

using std::vector;
using std::invalid_argument;
using std::default_random_engine;
using std::normal_distribution;

TEST(MethodOfMomentTest, ValidCalibrationReturnsThreeParams) 
{
    default_random_engine gen(42);
    normal_distribution<double> noise(0.0, 0.05);

    vector<double> series;
    double x = 1.0;
    for (int i = 0; i < 200; ++i) 
    {
        x = 0.9 * x + noise(gen);  // smooth mean-reversion with noise
        series.push_back(x);
    }

    MethodOfMoment mom;
    auto params = mom.calibrate(series);

    ASSERT_EQ(params.size(), 3);
    EXPECT_TRUE(std::isfinite(params[0]));
    EXPECT_TRUE(std::isfinite(params[1]));
    EXPECT_TRUE(std::isfinite(params[2]));

    EXPECT_GT(params[1], 0.0);
    EXPECT_GT(params[2], 0.0);
}

TEST(MethodOfMomentTest, TooShortThrows) 
{
    MethodOfMoment mom;
    vector<double> data = {1.0};
    EXPECT_THROW(mom.calibrate(data), invalid_argument);
}

int main(int argc, char **argv) 
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
