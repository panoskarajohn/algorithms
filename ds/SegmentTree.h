#pragma once

#include <memory>
#include <vector>

class SegmentTree {
  public:
    explicit SegmentTree(int total, int leftIndex, int rightIndex);
    // query and update validate bounds against the root range and throw
    // std::out_of_range on invalid inputs.
    int query(int left, int right) const;
    void update(int index, int val);
    // Adds val to every element in [l, r] in O(log N) via lazy propagation.
    void rangeUpdate(int l, int r, int val);
    int size() const;
    static std::shared_ptr<SegmentTree> build(const std::vector<int> &nums, int left, int right);
    // Build an empty (all-zero) tree over [left, right] with dynamic node
    // allocation — nodes are created on demand during updates.
    static std::shared_ptr<SegmentTree> buildEmpty(int left, int right);

  private:
    std::shared_ptr<SegmentTree> left;
    std::shared_ptr<SegmentTree> right;
    int leftIndex, rightIndex, sum, lazy;
    void pushDown();
    int queryImpl(int l, int r);
};
