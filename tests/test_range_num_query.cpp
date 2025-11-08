#include "range_num_query.h"
#include <gtest/gtest.h>

TEST(NumArrayTest, SingleElement) {
    std::vector<int> nums = {5};
    NumArray numArray(nums);

    EXPECT_EQ(numArray.sumRange(0, 0), 5);
}

TEST(NumArrayTest, MultipleElements) {
    std::vector<int> nums = {-2, 0, 3, -5, 2, -1};
    NumArray numArray(nums);

    EXPECT_EQ(numArray.sumRange(0, 2), 1);  // -2 + 0 + 3 = 1
    EXPECT_EQ(numArray.sumRange(2, 5), -1); // 3 + (-5) + 2 + (-1) = -1
    EXPECT_EQ(numArray.sumRange(0, 5), -3); // sum of all
}

TEST(NumArrayTest, PrefixSumLogic) {
    std::vector<int> nums = {1, 2, 3, 4};
    NumArray numArray(nums);

    auto result = numArray.sumRange(0, 1);
    EXPECT_EQ(result, 3); // 1 + 2

    result = numArray.sumRange(1, 3);
    EXPECT_EQ(result, 9); // 2 + 3 + 4

    result = numArray.sumRange(2, 2);
    EXPECT_EQ(result, 3); // single element
}

TEST(NumArrayTest, HandlesEmptyVector) {
    std::vector<int> nums;
    NumArray *numArray = new NumArray(nums);

    // Should not crash; though undefined logically, range queries on empty should be avoided.
    delete numArray;
}
