#include "SegmentTree.h"

SegmentTree::SegmentTree(int total, int leftIndex, int rightIndex) {
    this->sum = total;
    this->left = nullptr;
    this->right = nullptr;
    this->leftIndex = leftIndex;
    this->rightIndex = rightIndex;
}

/*@static*/
std::shared_ptr<SegmentTree> SegmentTree::build(const std::vector<int> &nums, int left, int right) {
    if (left == right) {
        return std::make_shared<SegmentTree>(nums[left], left, right);
    }

    int middle = (left + right) / 2;
    auto root = std::make_shared<SegmentTree>(0, left, right);
    root->left = SegmentTree::build(nums, left, middle);
    root->right = SegmentTree::build(nums, middle + 1, right);
    root->sum = root->left->sum + root->right->sum;

    return root;
}

int SegmentTree::query(int left, int right) const {
    if (left == this->leftIndex && right == this->rightIndex) {
        return this->sum;
    }

    int middle = (this->leftIndex + this->rightIndex) / 2;
    if (this->leftIndex > middle) {
        return this->right->query(this->leftIndex, this->rightIndex);
    } else if (this->rightIndex <= middle) {
        return this->left->query(this->leftIndex, this->rightIndex);
    } else {
        return (this->left->query(this->leftIndex, middle) + this->right->query(middle + 1, right));
    }
}

void SegmentTree::update(int index, int val) {
    if (this->leftIndex == this->rightIndex) {
        this->sum = val;
        return;
    }

    int middle = (this->leftIndex + this->rightIndex) / 2;
    if (index > middle) {
        this->right->update(index, val);
    } else {
        this->left->update(index, val);
    }

    this->sum = this->left->sum + this->right->sum;
}

int SegmentTree::size() const { return this->rightIndex - this->leftIndex + 1; }
