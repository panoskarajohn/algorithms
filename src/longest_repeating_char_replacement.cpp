#include "longest_repeating_char_replacement.h"
#include <unordered_map>

int characterReplacement(std::string s, int k) {
    int n = s.size();
    int left = 0;
    int maxFreq = 0;
    int result = 0;
    std::unordered_map<char, int> freq;

    for (int right = 0; right < n; right++) {
        char current = s[right];
        freq[current]++;
        int window = right - left + 1;
        int maxFreq = std::max(maxFreq, freq[current]);

        if (window - maxFreq > k) {
            char leftChar = s[left];
            left++;
            freq[leftChar]--;
        }

        result = std::max(result, right - left + 1);
    }

    return result;
}