#include "prefix_sum.h"
#include <gtest/gtest.h>

TEST(RangeQuery, SingleElement) {
    std::vector<int> nums = {5};
    NumArray numArray(nums);

    EXPECT_EQ(numArray.sumRange(0, 0), 5);
}

TEST(RangeQuery, MultipleElements) {
    std::vector<int> nums = {-2, 0, 3, -5, 2, -1};
    NumArray numArray(nums);

    EXPECT_EQ(numArray.sumRange(0, 2), 1);  // -2 + 0 + 3 = 1
    EXPECT_EQ(numArray.sumRange(2, 5), -1); // 3 + (-5) + 2 + (-1) = -1
    EXPECT_EQ(numArray.sumRange(0, 5), -3); // sum of all
}

TEST(RangeQuery, PrefixSumLogic) {
    std::vector<int> nums = {1, 2, 3, 4};
    NumArray numArray(nums);

    auto result = numArray.sumRange(0, 1);
    EXPECT_EQ(result, 3); // 1 + 2

    result = numArray.sumRange(1, 3);
    EXPECT_EQ(result, 9); // 2 + 3 + 4

    result = numArray.sumRange(2, 2);
    EXPECT_EQ(result, 3); // single element
}

TEST(RangeQuery, HandlesEmptyVector) {
    std::vector<int> nums;
    NumArray *numArray = new NumArray(nums);

    // Should not crash; though undefined logically, range queries on empty should be avoided.
    delete numArray;
}

TEST(RangeQueryMatrix, VeryBasic) {
    std::vector<std::vector<int>> nums = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};

    NumMatrix nm(nums);

    // Test single element
    EXPECT_EQ(nm.sumRegion(0, 0, 0, 0), 1);

    // Test first row
    EXPECT_EQ(nm.sumRegion(0, 0, 0, 2), 6);

    // Test first column
    EXPECT_EQ(nm.sumRegion(0, 0, 2, 0), 12);

    // Test 2x2 subregion
    EXPECT_EQ(nm.sumRegion(1, 1, 2, 2), 28);

    // Test entire matrix
    EXPECT_EQ(nm.sumRegion(0, 0, 2, 2), 45);
}

TEST(RangeQueryMatrix, VeryBasic2) {
    std::vector<std::vector<int>> nums = {{3, 0, 1}, {5, 6, 3}, {1, 2, 0}};

    NumMatrix nm(nums);

    // Test single elements
    EXPECT_EQ(nm.sumRegion(0, 0, 0, 0), 3);
    EXPECT_EQ(nm.sumRegion(1, 1, 1, 1), 6);
    EXPECT_EQ(nm.sumRegion(2, 2, 2, 2), 0);

    // Test first row
    EXPECT_EQ(nm.sumRegion(0, 0, 0, 2), 4); // 3 + 0 + 1

    // Test middle row
    EXPECT_EQ(nm.sumRegion(1, 0, 1, 2), 14); // 5 + 6 + 3

    // Test first column
    EXPECT_EQ(nm.sumRegion(0, 0, 2, 0), 9); // 3 + 5 + 1

    // Test 2x2 subregions
    EXPECT_EQ(nm.sumRegion(0, 0, 1, 1), 14); // 3 + 0 + 5 + 6
    EXPECT_EQ(nm.sumRegion(1, 1, 2, 2), 11); // 6 + 3 + 2 + 0

    // Test entire matrix
    EXPECT_EQ(nm.sumRegion(0, 0, 2, 2), 21); // sum of all elements

    // Test 2x3 subregion
    EXPECT_EQ(nm.sumRegion(0, 0, 1, 2), 18); // top 2 rows
}

TEST(PivotIndex, VeryBasic) {
    std::vector<int> nums = {1, 7, 3, 6, 5, 6};
    EXPECT_EQ(pivotIndex(nums), 3);

    nums = {1, 2, 3};
    EXPECT_EQ(pivotIndex(nums), -1);

    nums = {10};
    EXPECT_EQ(pivotIndex(nums), 0);

    nums = {2, 1, -1};
    EXPECT_EQ(pivotIndex(nums), 0);
}
