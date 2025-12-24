#include <two_sum_two.h>

std::vector<int> twoSumTwo(std::vector<int> &numbers, int target) {
    // we get the array in an asc order
    std::vector<int> result;
    int left = 0;
    int right = numbers.size() - 1;

    while (true) {
        int left_num = numbers[left];
        int right_num = numbers[right];
        int sum = left_num + right_num;

        if (left != right && sum == target) {
            result.push_back(left + 1);
            result.push_back(right + 1);
            break;
        }

        if (sum < target) {
            left++;
        }

        if (sum > target) {
            right--;
        }
    }

    return result;
}