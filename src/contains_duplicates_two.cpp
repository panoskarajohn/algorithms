#include "contains_duplicates_two.h"
#include <unordered_map>

bool containsNearbyDupicates(const std::vector<int> &nums, int k) {
  const int n = nums.size();
  std::unordered_map<int, int> map;

  map.insert({nums[0], 0});

  for (int i = 1; i < nums.size(); i++) {
    int current = nums[i];
    std::unordered_map<int, int>::iterator it = map.find(current);

    if (it != map.end()) {
      const int keyFound = it->first;
      const int indexFound = it->second;

      if (i - indexFound <= k) {
        return true;
      } else {
        map[nums[i]] = i;
      }
    }

    map.insert({nums[i], i});
  }

  return false;
}
