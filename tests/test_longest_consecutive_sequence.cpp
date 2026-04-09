#include "longest_consecutive_sequence.h"
#include <gtest/gtest.h>

TEST(LongestConsecutiveSequence, VeryBasic) {
    {
        // Basic case
        std::vector<int> nums = {100, 4, 200, 1, 3, 2};
        int result = longestConsecutive(nums);
        EXPECT_EQ(result, 4);
    }
    {
        // Longer sequence
        std::vector<int> nums = {0, 3, 7, 2, 5, 8, 4, 6, 0, 1};
        int result = longestConsecutive(nums);
        EXPECT_EQ(result, 9);
    }
    {
        // Empty
        std::vector<int> nums = {};
        int result = longestConsecutive(nums);
        EXPECT_EQ(result, 0);
    }
    {
        // Single element
        std::vector<int> nums = {42};
        int result = longestConsecutive(nums);
        EXPECT_EQ(result, 1);
    }
    {
        // All duplicates
        std::vector<int> nums = {1, 1, 1};
        int result = longestConsecutive(nums);
        EXPECT_EQ(result, 1);
    }
}
