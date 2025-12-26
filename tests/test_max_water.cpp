#include "max_water.h"
#include <gtest/gtest.h>

TEST(MaxWater, VeryBasic) {
    std::vector<int> nums = {1, 7, 2, 5, 4, 7, 3, 6};
    int result = maxWater(nums);
    int expected = 36;
    EXPECT_EQ(result, expected);

    std::vector<int> nums2 = {2, 2, 2};
    int result2 = maxWater(nums2);
    int expected2 = 4;
    EXPECT_EQ(result2, expected2);
}

TEST(TrapWater, VeryBasic) {
    std::vector<int> nums = {0, 2, 0, 3, 1, 0, 1, 3, 2, 1};
    int expected = 9;

    int result = trapWater(nums);
    ASSERT_EQ(result, expected);
}

TEST(TrapWaterTwoPtr, VeryBasic) {
    std::vector<int> nums = {0, 2, 0, 3, 1, 0, 1, 3, 2, 1};
    int expected = 9;

    int result = trapWaterTwoPointers(nums);
    ASSERT_EQ(result, expected);
}