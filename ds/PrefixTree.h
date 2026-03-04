#pragma once

#include <memory>
#include <set>
#include <string>
#include <utility>
#include <vector>

class PrefixTree {
  public:
    PrefixTree();
    ~PrefixTree();

    void insert(const std::string &word);
    bool startsWith(const std::string &prefix) const;
    bool search(const std::string &word) const;
    std::vector<std::string> searchWordsInBoard(const std::vector<std::vector<char>> &board);

  private:
    struct Node;
    std::unique_ptr<Node> root;
    void checkPosition(const std::vector<std::vector<char>> &board, int row, int col,
                       const Node *node, std::vector<std::vector<bool>> &visited,
                       std::string &current, std::set<std::string> &found) const;
};
