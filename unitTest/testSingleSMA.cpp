#include "SingleSMA.h"
#include <gtest/gtest.h>
#include <vector>
#include <stdexcept>

using std::vector;
using std::invalid_argument;

TEST(SingleSMATest, NormalCase) 
{
    vector<double> data = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    SingleSMA sma(3);
    sma.compute(data);
    const auto& result = sma.getValue();

    vector<double> expected = {
        (1+2+3)/3.0, (2+3+4)/3.0, (3+4+5)/3.0, (4+5+6)/3.0,
        (5+6+7)/3.0, (6+7+8)/3.0, (7+8+9)/3.0, (8+9+10)/3.0
    };

    ASSERT_EQ(result.size(), expected.size());
    for (size_t i = 0; i < result.size(); ++i) {
        EXPECT_NEAR(result[i], expected[i], 1e-6);
    }
}

TEST(SingleSMATest, WindowLargerThanData) 
{
    vector<double> data = {1, 2};
    SingleSMA sma(5);
    EXPECT_THROW(sma.compute(data), invalid_argument);
}

TEST(SingleSMATest, InvalidWindow) 
{
    EXPECT_THROW(SingleSMA(0), invalid_argument);
    EXPECT_THROW(SingleSMA(-3), invalid_argument);
}

int main(int argc, char **argv) 
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
