#include "remove_duplicates_in_place.h"
#include <limits>

int removeDuplicates(std::vector<int> &nums) {
    int n = nums.size() - 1;
    int lastVisited = std::numeric_limits<int>::max();

    for (int i = n; i >= 0; i--) {
        int current = nums[i];
        if (lastVisited == current) {
            nums.erase(nums.begin() + i + 1); // erase the last visited
        } else {
            lastVisited = current;
        }
    }

    return nums.size();
}