#include "find_duplicate_number.h"
#include <gtest/gtest.h>

TEST(FindDuplicateNumber, VeryBasic) {
    {
        std::vector<int> nums = {1, 3, 4, 2, 2};
        EXPECT_EQ(findDuplicate(nums), 2);
    }

    {
        std::vector<int> nums = {3, 1, 3, 4, 2};
        EXPECT_EQ(findDuplicate(nums), 3);
    }

    {
        std::vector<int> nums = {1, 1};
        EXPECT_EQ(findDuplicate(nums), 1);
    }

    {
        std::vector<int> nums = {1, 1, 2};
        EXPECT_EQ(findDuplicate(nums), 1);
    }

    {
        std::vector<int> nums = {2, 5, 9, 6, 9, 3, 8, 9, 7, 1};
        EXPECT_EQ(findDuplicate(nums), 9);
    }
}
