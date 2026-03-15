#pragma once

#include <vector>

/**
 * @class UnionFind
 * @brief A Disjoint Set Union (DSU) data structure with path compression and union by rank.
 *
 * UnionFind supports efficient:
 * - Finding the representative of a set (find)
 * - Merging two sets (unite)
 * - Checking if two elements are in the same set (same)
 * - Getting the size of a component (sizeOfComponent)
 *
 * Time Complexity:
 * - find, unite, same: O(alpha(n)) amortized, where alpha is the inverse Ackermann function
 * - This is effectively O(1) for all practical purposes.
 *
 * Space Complexity: O(n)
 *
 * @example
 * @code
 * UnionFind uf(5);  // Create sets {0}, {1}, {2}, {3}, {4}
 * uf.unite(0, 1);  // Merge sets containing 0 and 1
 * uf.unite(2, 3);  // Merge sets containing 2 and 3
 * uf.same(0, 1);   // Returns true
 * uf.same(0, 2);   // Returns false
 * uf.sizeOfComponent(0);  // Returns 2
 * @endcode
 */
class UnionFind {
  public:
    /**
     * @brief Constructs a UnionFind instance with n isolated elements.
     * @param size Number of elements (must be non-negative)
     * @throws std::out_of_range if size is negative
     */
    explicit UnionFind(int size);
    ~UnionFind();

    /**
     * @brief Finds the representative (root) of the set containing x.
     *
     * Uses path compression to flatten the tree structure,
     * making future operations faster.
     *
     * @param x Element index (0 <= x < size)
     * @return Representative of the set containing x
     */
    int find(int x);

    /**
     * @brief Merges the sets containing elements a and b.
     *
     * Uses union by rank to keep trees balanced.
     *
     * @param a First element
     * @param b Second element
     * @return true if sets were merged, false if already in same set
     */
    bool unite(int a, int b);

    /**
     * @brief Checks if two elements are in the same set.
     * @param a First element
     * @param b Second element
     * @return true if both elements are in the same set
     */
    bool same(int a, int b);

    /**
     * @brief Returns the size of the set containing element x.
     * @param x Element to query
     * @return Number of elements in the component containing x
     */
    int sizeOfComponent(int x);

    /**
     * @brief Returns the total number of elements.
     * @return The size passed to the constructor
     */
    int count() const;

  private:
    std::vector<int> parent; ///< Parent pointer array; parent[i] = parent of i
    std::vector<int> rank;   ///< Upper bound on tree depth for each root
    std::vector<int> sizes;  ///< Size of each component (valid only at root)
    int componentCount;
};
