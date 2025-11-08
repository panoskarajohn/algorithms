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