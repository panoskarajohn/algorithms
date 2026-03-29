#include "connected_components.h"
#include "UnionFind.h"

int countComponents(int n, const std::vector<std::vector<int>> &edges) {
    int components = n;
    UnionFind uf{n};

    for (const auto &edge : edges) {
        if (uf.unite(edge[0], edge[1])) {
            components--;
        }
    }
    return components;
}
