#include "SegmentTree.h"

#include <gtest/gtest.h>

// ─── Construction ────────────────────────────────────────────────────────────

TEST(SegmentTree, SizeAfterConstruction) {
    std::vector<int> nums = {1, 2, 3, 4, 5};
    auto st = SegmentTree::build(nums, 0, nums.size() - 1);
    EXPECT_EQ(st->size(), 5);
}

TEST(SegmentTree, SingleElement) {
    std::vector<int> nums = {42};
    auto st = SegmentTree::build(nums, 0, 0);
    EXPECT_EQ(st->size(), 1);
    EXPECT_EQ(st->query(0, 0), 42);
}

// ─── Range sum queries ────────────────────────────────────────────────────────

TEST(SegmentTree, FullRangeQuery) {
    std::vector<int> nums = {1, 3, 5, 7, 9, 11};
    auto st = SegmentTree::build(nums, 0, nums.size() - 1);
    EXPECT_EQ(st->query(0, 5), 36);
}

TEST(SegmentTree, PartialRangeQuery) {
    std::vector<int> nums = {1, 3, 5, 7, 9, 11};
    auto st = SegmentTree::build(nums, 0, nums.size() - 1);
    EXPECT_EQ(st->query(1, 3), 15);  // 3 + 5 + 7
}

TEST(SegmentTree, SingleElementQuery) {
    std::vector<int> nums = {1, 3, 5, 7, 9, 11};
    auto st = SegmentTree::build(nums, 0, nums.size() - 1);
    EXPECT_EQ(st->query(2, 2), 5);
}

TEST(SegmentTree, FirstElementQuery) {
    std::vector<int> nums = {4, 8, 15, 16, 23, 42};
    auto st = SegmentTree::build(nums, 0, nums.size() - 1);
    EXPECT_EQ(st->query(0, 0), 4);
}

TEST(SegmentTree, LastElementQuery) {
    std::vector<int> nums = {4, 8, 15, 16, 23, 42};
    auto st = SegmentTree::build(nums, 0, nums.size() - 1);
    EXPECT_EQ(st->query(5, 5), 42);
}

TEST(SegmentTree, QueryWithNegativeValues) {
    std::vector<int> nums = {-3, -1, 0, 2, 5};
    auto st = SegmentTree::build(nums, 0, nums.size() - 1);
    EXPECT_EQ(st->query(0, 4), 3);   // total sum
    EXPECT_EQ(st->query(0, 1), -4);  // -3 + -1
    EXPECT_EQ(st->query(1, 3), 1);   // -1 + 0 + 2
}

TEST(SegmentTree, QueryWithAllZeros) {
    std::vector<int> nums = {0, 0, 0, 0};
    auto st = SegmentTree::build(nums, 0, nums.size() - 1);
    EXPECT_EQ(st->query(0, 3), 0);
}

// ─── Point updates ────────────────────────────────────────────────────────────

TEST(SegmentTree, UpdateThenQuery) {
    std::vector<int> nums = {1, 3, 5, 7, 9, 11};
    auto st = SegmentTree::build(nums, 0, nums.size() - 1);
    st->update(1, 10);               // Change index 1 from 3 to 10
    EXPECT_EQ(st->query(1, 3), 22);  // 10 + 5 + 7
}

TEST(SegmentTree, UpdateFirstElement) {
    std::vector<int> nums = {1, 2, 3};
    auto st = SegmentTree::build(nums, 0, nums.size() - 1);
    st->update(0, 100);
    EXPECT_EQ(st->query(0, 0), 100);
    EXPECT_EQ(st->query(0, 2), 105);  // 100 + 2 + 3
}

TEST(SegmentTree, UpdateLastElement) {
    std::vector<int> nums = {1, 2, 3};
    auto st = SegmentTree::build(nums, 0, nums.size() - 1);
    st->update(2, 99);
    EXPECT_EQ(st->query(2, 2), 99);
    EXPECT_EQ(st->query(0, 2), 102);  // 1 + 2 + 99
}

TEST(SegmentTree, MultipleUpdates) {
    std::vector<int> nums = {1, 2, 3, 4, 5};
    auto st = SegmentTree::build(nums, 0, nums.size() - 1);
    st->update(0, 10);
    st->update(4, 50);
    EXPECT_EQ(st->query(0, 4), 69);  // 10 + 2 + 3 + 4 + 50
}

TEST(SegmentTree, UpdateToNegative) {
    std::vector<int> nums = {5, 5, 5};
    auto st = SegmentTree::build(nums, 0, nums.size() - 1);
    st->update(1, -10);
    EXPECT_EQ(st->query(0, 2), 0);  // 5 + (-10) + 5
}

TEST(SegmentTree, UpdateSameIndexTwice) {
    std::vector<int> nums = {1, 2, 3};
    auto st = SegmentTree::build(nums, 0, nums.size() - 1);
    st->update(1, 20);
    st->update(1, 7);
    EXPECT_EQ(st->query(1, 1), 7);
    EXPECT_EQ(st->query(0, 2), 11);  // 1 + 7 + 3
}

// ─── Out-of-range behaviour ───────────────────────────────────────────────────

TEST(SegmentTree, QueryOutOfRangeThrows) {
    std::vector<int> nums = {1, 2, 3};
    auto st = SegmentTree::build(nums, 0, nums.size() - 1);
    EXPECT_THROW(st->query(-1, 2), std::out_of_range);
    EXPECT_THROW(st->query(0, 3), std::out_of_range);
    EXPECT_THROW(st->query(2, 1), std::out_of_range);  // left > right
}

TEST(SegmentTree, UpdateOutOfRangeThrows) {
    std::vector<int> nums = {1, 2, 3};
    auto st = SegmentTree::build(nums, 0, nums.size() - 1);
    EXPECT_THROW(st->update(-1, 5), std::out_of_range);
    EXPECT_THROW(st->update(3, 5), std::out_of_range);
}
