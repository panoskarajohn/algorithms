#include "UnionFind.h"
#include <numeric>
#include <utility>
UnionFind::~UnionFind() {}

UnionFind::UnionFind(int size) : parent(size), rank(size, 1), sizes(size, 1) {
    if (size < 0) {
        throw std::out_of_range("UnionFind index out of range");
    }
    // Initialize each element as its own parent (self-loop)
    // This creates n singleton sets
    std::iota(parent.begin(), parent.end(), 0);
}

/**
 * @brief Finds the root representative with path compression.
 *
 * Recursively traverses up the tree, making each node point directly
 * to the root. This flattens the structure, improving future lookups.
 *
 * Before: 0 -> 1 -> 2 -> 3 (root)
 * After:  0 -> 3, 1 -> 3, 2 -> 3
 */
int UnionFind::find(int x) {
    if (parent[x] != x) {
        parent[x] = find(parent[x]); // Path compression
    }
    return parent[x];
}

/**
 * @brief Merges two sets using union by rank.
 *
 * Attaches the smaller tree under the root of the larger tree.
 * This keeps the tree height bounded by O(log n).
 *
 * @return false if a and b were already in the same set
 */
bool UnionFind::unite(int a, int b) {
    int rootA = find(a);
    int rootB = find(b);

    if (rootA == rootB) {
        return false; // Already in same set
    }

    // Union by rank: attach smaller tree under larger tree
    if (rank[rootA] < rank[rootB]) {
        std::swap(rootA, rootB);
    }

    // Merge rootB into rootA
    parent[rootB] = rootA;
    sizes[rootA] += sizes[rootB];

    // Increment rank if both trees had equal height
    if (rank[rootA] == rank[rootB]) {
        rank[rootA]++;
    }

    return true;
}

/**
 * @brief Checks if two elements belong to the same set.
 * @param a First element
 * @param b Second element
 * @return true if both elements have the same representative
 */
bool UnionFind::same(int a, int b) { return find(a) == find(b); }

/**
 * @brief Returns the number of elements in the set containing x.
 *
 * Uses the sizes array maintained at the root to provide O(1) lookup.
 * Note: sizes are only accurate at root indices.
 *
 * @param x Element to query
 * @return Size of the component containing x
 */
int UnionFind::sizeOfComponent(int x) { return sizes[find(x)]; }

/**
 * @brief Returns the total number of elements in the data structure.
 * @return The number of elements passed during construction
 */
int UnionFind::count() const { return static_cast<int>(parent.size()); }
