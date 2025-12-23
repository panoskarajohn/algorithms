#include "palindrome.h"
#include <gtest/gtest.h>
#include <string>

TEST(Palindrome, VeryBasic) {
    auto s = "Was it a car or a cat I saw?";
    bool result = isPalindrome(s);
    EXPECT_TRUE(result);

    auto s2 = "tab a cat";
    bool result2 = isPalindrome(s2);
    EXPECT_FALSE(result2);
}