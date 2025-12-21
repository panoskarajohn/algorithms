#include "max_cont_char_w_repeating.h"
#include <limits>

int lengthOfLongestSubstring(std::string s) {
    bool characters[255] = {false};
    int min = std::numeric_limits<int>::min();
    int result = min;
    int counter = 0;
    int n = s.length();
    int left = 0;

    for (int right = 0; right < n; right++) {
        int code = (int)s[right];
        if (characters[code]) {
            result = std::max(result, counter);
            right = left;
            left++;
            std::fill(std::begin(characters), std::end(characters), false);
            counter = 0;
        } else {
            characters[code] = true;
            counter++;
            result = std::max(result, counter);
        }
    }

    if (result == min)
        return 0;

    return std::max(result, counter);
}
