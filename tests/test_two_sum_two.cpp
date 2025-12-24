#include "_test_utils.h"
#include "two_sum_two.h"
#include <future>
#include <gtest/gtest.h>
#include <vector>

TEST(TwoSumTwo, VERYBASIC) {
    std::vector<int> numbers = {1, 2, 3, 4};
    int target = 3;
    std::vector<int> expected = {1, 2};

    std::vector<int> result;
    ASSERT_NO_THROW({
        result = runWithTimeout(1000, [&]() { return twoSumTwo(numbers, target); });
    }) << "Infinite loop detected!";
    ASSERT_EQ(result, expected);
}

TEST(TwoSumTwo, Failed) {
    std::vector<int> numbers = {-5, -3, 0, 2, 4, 6, 8};
    int target = 5;
    std::vector<int> expected = {2, 7};

    std::vector<int> result;
    ASSERT_NO_THROW({
        result = runWithTimeout(1000, [&]() { return twoSumTwo(numbers, target); });
    }) << "Infinite loop detected!";

    ASSERT_EQ(result, expected);
}