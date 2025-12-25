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