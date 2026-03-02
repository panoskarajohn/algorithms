#pragma once

#include <memory>
#include <string>
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
};
