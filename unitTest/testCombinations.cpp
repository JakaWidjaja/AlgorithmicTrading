#include "Combinations.h"
#include <gtest/gtest.h>
#include <vector>
#include <string>
#include <algorithm>

using std::vector;
using std::string;

TEST(CombinationsTest, ThreeChooseTwo) 
{
    vector<string> items = {"A", "B", "C"};
    Combinations comb;
    auto result = comb.generate(items, 2);

    vector<vector<string>> expected = 
    {
        {"A", "B"},
        {"A", "C"},
        {"B", "C"}
    };

    ASSERT_EQ(result.size(), expected.size());

    for (const auto& combo : expected) 
    {
        EXPECT_NE(std::find(result.begin(), result.end(), combo), result.end());
    }
}

TEST(CombinationsTest, ChooseAll) 
{
    vector<string> items = {"X", "Y", "Z"};
    Combinations comb;
    auto result = comb.generate(items, 3);

    ASSERT_EQ(result.size(), 1);
    EXPECT_EQ(result[0], items);
}

TEST(CombinationsTest, ChooseNone) 
{
    vector<string> items = {"1", "2", "3"};
    Combinations comb;
    auto result = comb.generate(items, 0);

    ASSERT_EQ(result.size(), 1);
    EXPECT_TRUE(result[0].empty());
}

TEST(CombinationsTest, InvalidCaseTooLarge) 
{
    vector<string> items = {"a", "b"};
    Combinations comb;
    auto result = comb.generate(items, 3);
    EXPECT_TRUE(result.empty());
}

int main(int argc, char **argv) 
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
