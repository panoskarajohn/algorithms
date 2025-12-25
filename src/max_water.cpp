#include "max_water.h"

int maxWater(std::vector<int> heights) {
    int n = heights.size();
    int left = 0;
    int right = n - 1;
    int result = std::numeric_limits<int>::min();

    while (left != right) {
        int distance = right - left;
        int leftHeight = heights[left];
        int rightHeight = heights[right];
        int height = std::min(leftHeight, rightHeight);
        int area = distance * height;

        result = std::max(result, area);

        if (leftHeight < rightHeight) {
            left++;
        } else {
            right--;
        }
    }

    return result;
}