#include "longest_repeating_char_replacement.h"
#include <gtest/gtest.h>

TEST(LongestRepeatingCharReplacement, VeryBasic) {
    std::string s1 = "XYYX";
    int k = 2;
    int expected = 4;
    int result = characterReplacement(s1, k);
    EXPECT_EQ(result, expected);

    std::string s2 = "AAABABB";
    int k2 = 1;
    int expected2 = 5;
    int result2 = characterReplacement(s2, k2);
    EXPECT_EQ(result2, expected2);
}

TEST(LongestRepeatingCharReplacement, Failed) {
    std::string s1 = "ABAA";
    int k = 0;
    int expected = 2;
    int result = characterReplacement(s1, k);
    EXPECT_EQ(result, expected);
}

TEST(LongestRepeatingCharReplacement, Failed2) {
    std::string s1 = "ABBB";
    int k = 2;
    int expected = 4;
    int result = characterReplacement(s1, k);
    EXPECT_EQ(result, expected);
}