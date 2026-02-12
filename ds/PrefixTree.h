#pragma once

#include <memory>
#include <string>

class PrefixTree {
  public:
    PrefixTree();
    ~PrefixTree();

    void insert(const std::string &word);
    bool startsWith(const std::string &prefix) const;

  private:
    struct Node;
    std::unique_ptr<Node> root;
};
