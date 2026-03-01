#pragma once

#include <memory>
#include <string>

class WordDictionary {
  public:
    WordDictionary();
    ~WordDictionary();

    void addWord(const std::string &word);
    bool search(const std::string &word) const;
    bool searchIterative(const std::string &word) const;

  private:
    struct Node;
    std::unique_ptr<Node> root;
    bool dfs(int i, const Node *root, const std::string &word) const;
};
