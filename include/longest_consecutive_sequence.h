#pragma once

#include <vector>

// Given an unsorted array of integers, return the length of the
// longest consecutive elements sequence.
//
// Example:
//   nums = [100, 4, 200, 1, 3, 2] -> 4  (sequence: 1, 2, 3, 4)
//   nums = [0, 3, 7, 2, 5, 8, 4, 6, 0, 1] -> 9  (sequence: 0..8)
int longestConsecutive(const std::vector<int> &nums);
