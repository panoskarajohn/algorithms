#pragma once

#include <memory>
#include <vector>

class SegmentTree {
  public:
    explicit SegmentTree(int total, int leftIndex, int rightIndex);
    int query(int left, int right) const;
    void update(int index, int val);
    int size() const;
    static std::shared_ptr<SegmentTree> build(const std::vector<int> &nums, int left, int right);

  private:
    std::shared_ptr<SegmentTree> left;
    std::shared_ptr<SegmentTree> right;
    int leftIndex, rightIndex, sum;
};
