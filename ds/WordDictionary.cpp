#include "WordDictionary.h"

#include <stdexcept>

WordDictionary::WordDictionary() = default;

WordDictionary::~WordDictionary() = default;

void WordDictionary::addWord(const std::string &word) {
    (void)word;
    throw std::logic_error("WordDictionary::addWord is not implemented");
}

bool WordDictionary::search(const std::string &word) const {
    (void)word;
    throw std::logic_error("WordDictionary::search is not implemented");
}
