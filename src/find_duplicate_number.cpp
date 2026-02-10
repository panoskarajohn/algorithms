#include "find_duplicate_number.h"
#include <stdexcept>

int findDuplicate(std::vector<int> &nums) {
    for (int i = 0; i < nums.size(); i++) {
        int index = abs(nums[i]);
        if (nums[index] < 0) {
            return index;
        }
        nums[index] = nums[index] * -1;
    }

    return -1; // we should never reach here based on the problem description
}
