#include "min_sub_array_len.h"
#include <gtest/gtest.h>
TEST(MinSubArrayLength, VeryBasic) {
    const std::vector<int> nums = {2, 1, 5, 1, 5, 3};
    const int target = 10;
    const int expected = 3;
    const int result = minSubArrayLen(target, nums);
    EXPECT_EQ(expected, result);
}