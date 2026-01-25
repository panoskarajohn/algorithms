#include <vector>

class NumArray {
  public:
    NumArray(const std::vector<int> &nums);
    int sumRange(int left, int right);
    ~NumArray();

  private:
    int *prefixSumArray;
    int prefixSumArraySize;
};

class NumMatrix {
  public:
    NumMatrix(const std::vector<std::vector<int>> &nums);
    int sumRegion(int row1, int col1, int row2, int col2);

  private:
    std::vector<std::vector<int>> matrix;
};

int pivotIndex(std::vector<int> &nums);

std::vector<int> productExceptSelf(const std::vector<int> &nums);