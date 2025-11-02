#include "contains_duplicates_two.h"
#include <gtest/gtest.h>

TEST(ContainsDuplicates, VeryBasic) {
  const std::vector<int> nums = {1, 2, 3, 1};
  bool contains = containsNearbyDupicates(nums, 3);
  EXPECT_TRUE(contains);

  const std::vector<int> nums2 = {2, 1, 2};
  bool contains2 = containsNearbyDupicates(nums2, 1);
  EXPECT_FALSE(contains2);
}
