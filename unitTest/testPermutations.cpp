#include "Permutations.h"
#include <gtest/gtest.h>
#include <vector>
#include <string>
#include <algorithm>
#include <unordered_set>

using std::vector;
using std::string;

// Helper: Convert vector<vector<string>> to a set of joined strings
std::unordered_set<string> toStringSet(const vector<vector<string>>& perms) 
{
    std::unordered_set<string> result;
    for (const auto& p : perms) 
    {
        string joined;
        for (const auto& s : p) joined += s;
        result.insert(joined);
    }
    return result;
}

TEST(PermutationsTest, TwoFromThree) 
{
    vector<string> items = {"A", "B", "C"};
    Permutations perm;
    auto result = perm.generate(items, 2);

    // Expected permutations: AB, BA, AC, CA, BC, CB
    std::unordered_set<string> expected = 
    {
        "AB", "BA", "AC", "CA", "BC", "CB"
    };

    auto resultSet = toStringSet(result);
    EXPECT_EQ(resultSet.size(), expected.size());

    for (const auto& s : expected) 
    {
        EXPECT_TRUE(resultSet.find(s) != resultSet.end()) << "Missing permutation: " << s;
    }
}

TEST(PermutationsTest, ChooseAll) 
{
    vector<string> items = {"X", "Y"};
    Permutations perm;
    auto result = perm.generate(items, 2);

    EXPECT_EQ(result.size(), 2); // XY, YX
}

TEST(PermutationsTest, ChooseNone) 
{
    vector<string> items = {"X", "Y"};
    Permutations perm;
    auto result = perm.generate(items, 0);

    ASSERT_EQ(result.size(), 1);
    EXPECT_TRUE(result[0].empty());
}

TEST(PermutationsTest, ChooseTooManyReturnsEmpty) 
{
    vector<string> items = {"a", "b"};
    Permutations perm;
    auto result = perm.generate(items, 3);

    EXPECT_TRUE(result.empty());
}

int main(int argc, char **argv) 
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
