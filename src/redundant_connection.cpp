#include "redundant_connection.h"
#include "UnionFind.h"

std::vector<int> findRedundantConnection(std::vector<std::vector<int>> &edges) {
    int size = edges.size();
    UnionFind unionFind = UnionFind(size + 1);
    for (int i = 0; i < size; i++) {
        std::vector<int> current = edges[i];
        int first = current[0];
        int second = current[1];
        if (unionFind.same(first, second)) {
            return {first, second};
        }
        unionFind.unite(first, second);
    }

    // Should never reach here
    return {};
}
