#include "remove_duplicates_in_place.h"
#include <gtest/gtest.h>

TEST(RemoveDuplicates, VeryBasic) {
    std::vector<int> nums = {1, 1, 2, 3, 4};
    int result = removeDuplicates(nums);
    std::vector<int> resultVector = {1, 2, 3, 4};
    int expected = 4;

    EXPECT_EQ(expected, result);
    ASSERT_EQ(nums, resultVector);

    std::vector<int> nums2 = {2, 10, 10, 30, 30, 30};
    int result2 = removeDuplicates(nums2);
    std::vector<int> resultVector2 = {2, 10, 30};
    int expected2 = 3;

    EXPECT_EQ(expected2, result2);
    ASSERT_EQ(nums2, resultVector2);
}

TEST(RemoveDuplicatesTwo, VeryBasic) {
    std::vector<int> nums = {1, 1, 1, 2, 2, 3};
    int result = removeDuplicatesTwo(nums);
    std::vector<int> resultVector = {1, 1, 2, 2, 3};
    int expected = 5;

    EXPECT_EQ(expected, result);
    ASSERT_EQ(nums, resultVector);
}