#include "longest_consecutive_sequence.h"
#include "UnionFind.h"
#include <set>

int longestConsecutive(const std::vector<int> &nums) {
    std::set<int> numberSet;
    numberSet.insert(nums.begin(), nums.end());
    int size = static_cast<int>(nums.size());
    int max = 0;

    for (int i = 0; i < size; i++) {
        int current = nums[i];
        int length = 0;

        if (!numberSet.contains(current - 1)) { // means it's the most left number
            while (numberSet.contains(current + length)) {
                length++;
            }
            max = std::max(max, length);
        }
    }

    return max;
}
