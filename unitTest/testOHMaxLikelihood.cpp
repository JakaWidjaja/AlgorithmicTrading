#include "MaxLikelihood.h"
#include <gtest/gtest.h>
#include <vector>
#include <cmath>
#include <stdexcept>
#include <random>

using std::vector;
using std::invalid_argument;
using std::default_random_engine;
using std::normal_distribution;

TEST(MaxLikelihoodTest, ValidOUProcessCalibration) 
{
    default_random_engine gen(42);
    normal_distribution<double> noise(0.0, 0.05);

    vector<double> series;
    double x = 1.0;
    for (int i = 0; i < 200; ++i) {
        x = x - 0.05 * (x - 0.5) + noise(gen);  // OU process with noise
        series.push_back(x);
    }

    MaxLikelihood ml;
    auto params = ml.calibrate(series);

    EXPECT_EQ(params.size(), 3);
    EXPECT_GT(params[0], 0.0);              // mu
    EXPECT_NEAR(params[1], 0.05, 0.4);     // theta ≈ 0.05
    EXPECT_GT(params[2], 0.0);              // sigma
}

TEST(MaxLikelihoodTest, TooShortSeriesThrows) 
{
    MaxLikelihood ml;
    vector<double> series = {1.0};
    EXPECT_THROW(ml.calibrate(series), invalid_argument);
}

int main(int argc, char **argv) 
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
