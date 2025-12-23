#include "palindrome.h"
#include <iostream>

std::string keepOnlyLetters(const std::string &str) {
    std::string result;

    for (const char c : str) {
        if (std::isalnum(c)) {
            result += std::tolower(c);
        }
    }

    return result;
}

bool isPalindrome(std::string s) {
    const std::string alpha = keepOnlyLetters(s);
    int size = alpha.size();

    for (int left = 0; left < size; left++) {
        if (alpha[left] != alpha[size - left - 1]) {
            return false;
        }
    }

    return true;
}