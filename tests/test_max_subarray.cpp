#include "max_subarray.h"
#include <gtest/gtest.h>

TEST(MaxSubarrayTests, HandlesPositiveNumbers) {
  std::vector<int> nums = {1, 2, 3, 4};
  EXPECT_EQ(maxSubArray(nums), 10);
}

TEST(MaxSubarrayTests, HandlesMixedNumbers) {
  std::vector<int> nums = {-2, 1, -3, 4, -1, 2, 1, -5, 4};
  EXPECT_EQ(maxSubArray(nums), 6); // [4, -1, 2, 1]
}

TEST(MaxSubarrayTests, HandlesAllNegatives) {
  std::vector<int> nums = {-8, -3, -6, -2, -5, -4};
  EXPECT_EQ(maxSubArray(nums), -2);
}

TEST(MaxSubarrayTests, HandlesEmptyArray) {
  std::vector<int> nums = {};
  EXPECT_EQ(maxSubArray(nums), 0);
}

TEST(MaxSubarrayTests, HandlesSingleElement) {
  std::vector<int> nums = {5};
  EXPECT_EQ(maxSubArray(nums), 5);
}
