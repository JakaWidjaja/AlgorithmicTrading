#include "SavitzkyGolay.h"
#include <gtest/gtest.h>
#include <vector>
#include <stdexcept>
#include <cmath>

using std::vector;
using std::invalid_argument;

TEST(SavitzkyGolayTest, ValidSmoothing) 
{
    vector<double> data = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    SavitzkyGolay sg(5, 2);
    sg.compute(data);
    auto result = sg.getValue();

    EXPECT_EQ(result.size(), data.size());
    // Check that smoothing does not deviate too far from original data
    for (size_t i = 0; i < result.size(); ++i) {
        EXPECT_NEAR(result[i], data[i], 2.0);  // loose tolerance for smoothing
    }
}

TEST(SavitzkyGolayTest, EvenWindowThrows) 
{
    EXPECT_THROW(SavitzkyGolay(4, 2), invalid_argument);
}

TEST(SavitzkyGolayTest, PolyOrderTooHighThrows) 
{
    EXPECT_THROW(SavitzkyGolay(5, 6), invalid_argument);
}

TEST(SavitzkyGolayTest, InsufficientDataThrows) 
{
    vector<double> data = {1, 2, 3};
    SavitzkyGolay sg(7, 2);
    EXPECT_THROW(sg.compute(data), invalid_argument);
}

int main(int argc, char **argv) 
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
