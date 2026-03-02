#include "prefix_tree_problems.h"
#include "PrefixTree.h"
#include <stack>
#include <stdexcept>

std::vector<std::string> findWords(const std::vector<std::vector<char>> &board,
                                   std::vector<std::string> &words) {
    auto prefix = PrefixTree{};
    auto dfsStack = std::stack<char>{};
    for (const auto &word : words) {
        prefix.insert(word);
    }

    return prefix.searchWordsInBoard(board);
}
