#include <algorithm>
#include <limits>
#include <min_sub_array_len.h>

int minSubArrayLen(int target, const std::vector<int> &nums) {
    int left = 0;
    int n = nums.size();
    int sum = 0;
    int max = std::numeric_limits<int>::max();
    int result = max;

    for (int right = left; right < n; right++) {
        sum += nums[right];
        if (sum >= target) {
            result = std::min(result, right - left + 1);
            sum = 0;
            right = left; // right will be incremented by the for loop
            left++;
        }
    }

    if (result == max) {
        return 0;
    }

    return result;
}