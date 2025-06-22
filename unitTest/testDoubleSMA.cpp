#include "DoubleSMA.h"
#include <gtest/gtest.h>
#include <vector>
#include <stdexcept>

using std::vector;
using std::invalid_argument;

TEST(DoubleSMATest, NormalCase) 
{
    vector<double> data = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    DoubleSMA dsma(2, 4);
    dsma.compute(data);
    vector<double> result = dsma.getValue();

    // Manually compute expected double SMA
    // SMA(2) = [1.5, 2.5, 3.5, ..., 9.5]
    // SMA(4) = [2.5, 3.5, ..., 8.5]
    // Double SMA = SMA(2)[2:] - SMA(4)[]
    vector<double> expected = 
    {
        3.5 - 2.5,
        4.5 - 3.5,
        5.5 - 4.5,
        6.5 - 5.5,
        7.5 - 6.5,
        8.5 - 7.5,
        9.5 - 8.5
    };

    ASSERT_EQ(result.size(), expected.size());
    for (size_t i = 0; i < result.size(); ++i) {
        EXPECT_NEAR(result[i], expected[i], 1e-6);
    }
}

TEST(DoubleSMATest, ShortWindowTooLarge) 
{
    EXPECT_THROW(DoubleSMA(5, 4), invalid_argument);
}

TEST(DoubleSMATest, NonPositiveWindowThrows) 
{
    EXPECT_THROW(DoubleSMA(0, 5), invalid_argument);
    EXPECT_THROW(DoubleSMA(3, 0), invalid_argument);
}

TEST(DoubleSMATest, NotEnoughData) 
{
    vector<double> data = {1, 2, 3};  // too short for even SMA(4)
    DoubleSMA dsma(2, 4);
    dsma.compute(data);
    EXPECT_TRUE(dsma.getValue().empty());
}

int main(int argc, char **argv) 
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}