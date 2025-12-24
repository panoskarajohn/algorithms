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

int removeDuplicatesTwo(std::vector<int> &nums) {
    int n = nums.size();
    int max = std::numeric_limits<int>::max();
    int lastVisited = max;
    for (int i = n - 1; i >= 0; i--) {
        int current = nums[i];
        bool nextElement = i - 1 >= 0;
        int next = nextElement ? nums[i - 1] : max;
        if (current == lastVisited && current == next) {
            nums.erase(nums.begin() + i + 1); // erase the last visited
        } else {
            lastVisited = current;
        }
    }

    return nums.size();
}
