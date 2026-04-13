#include "SegmentTree.h"

#include <gtest/gtest.h>

TEST(SegmentTree, VeryBasic) {
    // ─── Construction / size ─────────────────────────────────────────────────
    {
        std::vector<int> nums = {1, 2, 3, 4, 5};
        auto st = SegmentTree::build(nums, 0, nums.size() - 1);
        EXPECT_EQ(st->size(), 5);
    }

    {
        std::vector<int> nums = {42};
        auto st = SegmentTree::build(nums, 0, 0);
        EXPECT_EQ(st->size(), 1);
        EXPECT_EQ(st->query(0, 0), 42);
    }

    {
        // size reflects the build range, not the full vector length
        std::vector<int> nums = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
        auto st = SegmentTree::build(nums, 0, nums.size() - 1);
        EXPECT_EQ(st->size(), 10);
    }

    {
        // size is stable after updates
        std::vector<int> nums = {1, 2, 3, 4, 5};
        auto st = SegmentTree::build(nums, 0, nums.size() - 1);
        st->update(0, 99);
        st->update(4, -99);
        EXPECT_EQ(st->size(), 5);
    }

    // ─── Range sum queries ────────────────────────────────────────────────────
    {
        std::vector<int> nums = {1, 3, 5, 7, 9, 11};
        auto st = SegmentTree::build(nums, 0, nums.size() - 1);

        EXPECT_EQ(st->query(0, 5), 36);   // full range
        EXPECT_EQ(st->query(1, 3), 15);   // 3+5+7
        EXPECT_EQ(st->query(2, 2), 5);    // single element mid
    }

    {
        std::vector<int> nums = {4, 8, 15, 16, 23, 42};
        auto st = SegmentTree::build(nums, 0, nums.size() - 1);

        EXPECT_EQ(st->query(0, 0), 4);    // first element
        EXPECT_EQ(st->query(5, 5), 42);   // last element
    }

    {
        std::vector<int> nums = {-3, -1, 0, 2, 5};
        auto st = SegmentTree::build(nums, 0, nums.size() - 1);

        EXPECT_EQ(st->query(0, 4), 3);    // total sum
        EXPECT_EQ(st->query(0, 1), -4);   // -3 + -1
        EXPECT_EQ(st->query(1, 3), 1);    // -1 + 0 + 2
    }

    {
        std::vector<int> nums = {0, 0, 0, 0};
        auto st = SegmentTree::build(nums, 0, nums.size() - 1);
        EXPECT_EQ(st->query(0, 3), 0);
    }

    // ─── Point updates ────────────────────────────────────────────────────────
    {
        std::vector<int> nums = {1, 3, 5, 7, 9, 11};
        auto st = SegmentTree::build(nums, 0, nums.size() - 1);
        st->update(1, 10);
        EXPECT_EQ(st->query(1, 3), 22);   // 10+5+7
    }

    {
        std::vector<int> nums = {1, 2, 3};
        auto st = SegmentTree::build(nums, 0, nums.size() - 1);
        st->update(0, 100);
        EXPECT_EQ(st->query(0, 0), 100);
        EXPECT_EQ(st->query(0, 2), 105);  // 100+2+3
    }

    {
        std::vector<int> nums = {1, 2, 3};
        auto st = SegmentTree::build(nums, 0, nums.size() - 1);
        st->update(2, 99);
        EXPECT_EQ(st->query(2, 2), 99);
        EXPECT_EQ(st->query(0, 2), 102);  // 1+2+99
    }

    {
        std::vector<int> nums = {1, 2, 3, 4, 5};
        auto st = SegmentTree::build(nums, 0, nums.size() - 1);
        st->update(0, 10);
        st->update(4, 50);
        EXPECT_EQ(st->query(0, 4), 69);   // 10+2+3+4+50
    }

    {
        std::vector<int> nums = {5, 5, 5};
        auto st = SegmentTree::build(nums, 0, nums.size() - 1);
        st->update(1, -10);
        EXPECT_EQ(st->query(0, 2), 0);    // 5+(-10)+5
    }

    {
        std::vector<int> nums = {1, 2, 3};
        auto st = SegmentTree::build(nums, 0, nums.size() - 1);
        st->update(1, 20);
        st->update(1, 7);
        EXPECT_EQ(st->query(1, 1), 7);
        EXPECT_EQ(st->query(0, 2), 11);   // 1+7+3
    }

    // ─── Out-of-range behaviour ───────────────────────────────────────────────
    {
        std::vector<int> nums = {1, 2, 3};
        auto st = SegmentTree::build(nums, 0, nums.size() - 1);

        EXPECT_THROW(st->query(-1, 2), std::out_of_range);
        EXPECT_THROW(st->query(0, 3), std::out_of_range);
        EXPECT_THROW(st->query(2, 1), std::out_of_range);  // left > right
        EXPECT_THROW(st->update(-1, 5), std::out_of_range);
        EXPECT_THROW(st->update(3, 5), std::out_of_range);
    }
}
