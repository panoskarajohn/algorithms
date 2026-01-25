#include "prefix_sum.h"

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

NumMatrix::NumMatrix(const std::vector<std::vector<int>> &nums) {
    if (nums.empty()) {
        matrix = {{}};
    }

    int rows = nums.size();
    int cols = nums[0].size();

    // Initialize matrix with the padded dimensions
    matrix.resize(rows + 1, std::vector<int>(cols + 1, 0));

    for (int row = 1; row <= rows; row++) {
        for (int col = 1; col <= cols; col++) {
            int above = matrix[row - 1][col];
            int left = matrix[row][col - 1];
            int diagonal = matrix[row - 1][col - 1];
            matrix[row][col] = nums[row - 1][col - 1] + above + left - diagonal;
        }
    }
}

int NumMatrix::sumRegion(int row1, int col1, int row2, int col2) {
    row1++;
    col1++;
    row2++;
    col2++;
    int total = matrix[row2][col2];
    int above = matrix[row1 - 1][col2];
    int left = matrix[row2][col1 - 1];
    int diagonal = matrix[row1 - 1][col1 - 1];

    return total - above - left + diagonal;
}

int pivotIndex(std::vector<int> &nums) {
    int n = nums.size();
    int total = 0;
    for (int num : nums) {
        total += num;
    }

    int leftSum = 0;
    for (int i = 0; i < n; i++) {
        int rightSum = total - leftSum - nums[i];
        if (leftSum == rightSum) {
            return i;
        }

        leftSum += nums[i];
    }

    return -1;
}

std::vector<int> productExceptSelf(const std::vector<int> &nums) {
    int n = nums.size();
    std::vector<int> result(n);
    std::vector<int> left(n);
    std::vector<int> right(n);

    int left_product = 1;
    int right_product = 1;

    for (int i = 0; i < n; i++) {
        left_product *= nums[i];
        right_product *= nums[n - i - 1];

        left[i] = left_product;
        right[n - i - 1] = right_product;
    }

    for (int i = 0; i < n; i++) {
        int prev = i - 1 >= 0 ? left[i - 1] : 1;
        int next = i + 1 < n ? right[i + 1] : 1;
        result[i] = prev * next;
    }

    return result;
}