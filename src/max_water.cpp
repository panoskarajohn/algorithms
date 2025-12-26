#include "max_water.h"
#include <map>

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

// TODO: There is a two pointer solution to this...
int trapWater(std::vector<int> heights) {
    int n = heights.size();
    std::unordered_map<int, int> maxLeftHeight;
    std::unordered_map<int, int> maxRightsHeight;

    maxLeftHeight[0] = 0;
    maxRightsHeight[n - 1] = 0;

    for (int i = 1; i < n; i++) {
        maxLeftHeight[i] = std::max(maxLeftHeight[i - 1], heights[i - 1]);
        maxRightsHeight[n - i - 1] = std::max(maxRightsHeight[n - i], heights[n - i]);
    }

    int sum = 0;
    for (int i = 0; i < n; i++) {
        int maxLeft = maxLeftHeight[i];
        int maxRight = maxRightsHeight[i];
        int mixOfMax = std::min(maxLeft, maxRight);
        int current = heights[i];

        int currentTrappedWater = mixOfMax - current;
        if (currentTrappedWater > 0) {
            sum += currentTrappedWater;
        }
    }

    return sum;
}