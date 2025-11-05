#include "number_of_subarrays_size_k_avg_gt_eq_thr.h"
#include <gtest/gtest.h>

TEST(SubArrKAvgGtEqThr, VeryBasic) {
  const std::vector<int> nums = {2, 2, 2, 2, 5, 5, 5, 8};
  int k = 3;
  int threshold = 4;
  int result = numOfSubarray(nums, k, threshold);
  EXPECT_EQ(result, 3);

  const std::vector<int> nums2 = {11, 13, 17, 23, 29, 31, 7, 5, 2, 3};
  int k2 = 3;
  int threshold2 = 5;

  result = numOfSubarray(nums2, k2, threshold2);
  EXPECT_EQ(result, 6);
}
