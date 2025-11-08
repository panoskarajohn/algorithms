#include "range_num_query.h"

NumArray::NumArray(const std::vector<int> &nums) {
    NumArray::prefixSumArraySize = nums.size();
    if (nums.size() == 0)
        return;
    NumArray::prefixSumArray = new int[prefixSumArraySize];
    int sum = 0;
    for (int i = 0; i < nums.size(); i++) {
        sum += nums[i];
        prefixSumArray[i] = sum;
    }
}

int NumArray::sumRange(int left, int right) {
    if (prefixSumArraySize == 0) {
        return 0;
    }

    int removeLeft = left - 1 < 0 ? 0 : NumArray::prefixSumArray[left - 1];
    int sum = prefixSumArray[right] - removeLeft;

    return sum;
}

NumArray::~NumArray() { delete[] prefixSumArray; }