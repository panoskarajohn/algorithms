#pragma once
#include <vector>

/**
 * @brief Finds the redundant edge that creates a cycle in an undirected graph.
 *
 * Given a graph that started as a tree with n nodes (labeled 1..n) and had
 * one additional edge added, return that extra edge. If multiple answers
 * exist, return the edge that appears last in the input.
 *
 * LeetCode 684 - Redundant Connection
 *
 * @param edges List of edges [u, v] forming the graph
 * @return The redundant edge [u, v] that forms a cycle
 *
 * Time Complexity:  O(n * alpha(n)) — near-linear with Union-Find
 * Space Complexity: O(n)
 */
std::vector<int> findRedundantConnection(std::vector<std::vector<int>> &edges);
