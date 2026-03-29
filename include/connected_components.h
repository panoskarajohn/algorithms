#pragma once

#include <vector>

// Given n nodes labeled 0 to n-1 and a list of undirected edges,
// return the number of connected components in the graph.
//
// Example:
//   n = 5, edges = [[0,1],[1,2],[3,4]] -> 2
//   n = 5, edges = [[0,1],[1,2],[2,3],[3,4]] -> 1
int countComponents(int n, const std::vector<std::vector<int>> &edges);
