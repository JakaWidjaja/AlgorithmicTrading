#include "HalfLife.h"
#include <gtest/gtest.h>
#include <vector>
#include <cmath>
#include <stdexcept>
#include <random>

using std::vector;
using std::invalid_argument;
using std::default_random_engine;
using std::normal_distribution;

TEST(HalfLifeTest, NormalCase) 
{
    default_random_engine gen(42);
    normal_distribution<double> noise(0.0, 0.1);

    vector<double> data;
    double x = 5.0;
    for (int i = 0; i < 100; ++i) {
        x = x - 0.1 * (x - 1.0) + noise(gen);  // add randomness
        data.push_back(x);
    }

    HalfLife hl;
    hl.compute(data);
    double val = hl.getValue();

    EXPECT_GT(val, 0.0);
    EXPECT_LT(val, 100.0);
}

TEST(HalfLifeTest, InsufficientData) 
{
    vector<double> data = {1.0};
    HalfLife hl;
    EXPECT_THROW(hl.compute(data), invalid_argument);
}

TEST(HalfLifeTest, ZeroVarianceLagged) 
{
    vector<double> data(100, 5.0);  // constant series
    HalfLife hl;
    EXPECT_THROW(hl.compute(data), invalid_argument);
}

int main(int argc, char **argv) 
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
