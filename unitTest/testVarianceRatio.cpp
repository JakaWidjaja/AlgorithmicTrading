#include "VarianceRatio.h"
#include <gtest/gtest.h>
#include <vector>
#include <stdexcept>
#include <cmath>

using std::vector;
using std::invalid_argument;

TEST(VarianceRatioTest, NormalCase) 
{
    vector<double> data(100);
    for (int i = 0; i < 100; ++i) {
        data[i] = i + ((i % 2 == 0) ? 0.1 : -0.1); 
    }

    VarianceRatio vr(2);
    vr.compute(data);
    double val = vr.getValue();

    EXPECT_GT(val, 0.0);
    EXPECT_LT(val, 10.0);  
}

TEST(VarianceRatioTest, LagTooSmall) 
{
    EXPECT_THROW(VarianceRatio(1), invalid_argument);
}

TEST(VarianceRatioTest, InvalidLagReset) 
{
    VarianceRatio vr(3);
    EXPECT_THROW(vr.setLag(1), invalid_argument);
}

TEST(VarianceRatioTest, NotEnoughData) 
{
    vector<double> data = {1.0, 2.0, 3.0};
    VarianceRatio vr(5);
    EXPECT_THROW(vr.compute(data), invalid_argument);
}

int main(int argc, char **argv) 
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
