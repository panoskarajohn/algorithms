#pragma once

#include <string>

class WordDictionary {
  public:
    WordDictionary();
    ~WordDictionary();

    void addWord(const std::string &word);
    bool search(const std::string &word) const;
};
