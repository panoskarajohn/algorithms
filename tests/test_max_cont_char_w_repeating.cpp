#include "max_cont_char_w_repeating.h"
#include <gtest/gtest.h>
#include <string>

TEST(MaxContinuousCharWithoutRepeating, VERYBASIC) {
    std::string s = "zxyzxyz";
    int expected = 3;

    int result = lengthOfLongestSubstring(s);
    EXPECT_EQ(result, expected);
}

TEST(MaxContinuousCharWithoutRepeating, Failed) {
    std::string s2 = "pwwkew";
    int expected2 = 3;

    int result = lengthOfLongestSubstring(s2);
    EXPECT_EQ(result, expected2);
}

TEST(MaxContinuousCharWithoutRepeating, Failed2) {
    std::string s2 = " ";
    int expected2 = 1;

    int result = lengthOfLongestSubstring(s2);
    EXPECT_EQ(result, expected2);
}

TEST(MaxContinuousCharWithoutRepeating, Failed3) {
    std::string s2 = "aab";
    int expected2 = 2;

    int result = lengthOfLongestSubstring(s2);
    EXPECT_EQ(result, expected2);
}