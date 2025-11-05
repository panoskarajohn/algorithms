#include "number_of_subarrays_size_k_avg_gt_eq_thr.h"

int numOfSubarray(const std::vector<int> &arr, int k, int threshold) {
  if (arr.size() < k) {
    return 0;
  }

  int sum = 0;
  int p1 = 0;
  int p2 = 0;
  int total = 0;
  while (p2 < arr.size()) {
    if (p2 - p1 >= k) {
      sum -= arr[p1++];
      sum += arr[p2++];
    } else {
      sum += arr[p2++];
    }
    bool distance = p2 - p1 == k;
    bool gt = sum / k >= threshold;
    if (distance && gt) {
      total++;
    }
  }
  return total;
}
