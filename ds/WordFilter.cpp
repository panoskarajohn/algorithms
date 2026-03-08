#include "WordFilter.h"
#include <array>

struct WordFilter::Node {
    std::array<std::unique_ptr<Node>, 27> children{};
    int maxWordIndex = -1;
};

WordFilter::WordFilter(const std::vector<std::string> &words) : root(std::make_unique<Node>()) {
    for (int wordIndex = 0; wordIndex < static_cast<int>(words.size()); ++wordIndex) {
        const std::string &word = words[wordIndex];
        const std::string combined = word + '{' + word;
        const size_t wordLength = word.size();

        for (size_t suffixStart = 0; suffixStart <= wordLength; ++suffixStart) {
            Node *current = root.get();

            for (size_t pos = suffixStart; pos < combined.size(); ++pos) {
                char currentChar = combined[pos];
                const int index = charToIndex(currentChar);
                if (!current->children[index]) {
                    current->children[index] = std::make_unique<Node>();
                }
                current = current->children[index].get();
                current->maxWordIndex = wordIndex;
            }
        }
    }
}

WordFilter::~WordFilter() {}

int WordFilter::f(std::string prefix, std::string suffix) {
    const std::string query = suffix + '{' + prefix;
    Node *current = root.get();
    for (const char c : query) {
        const int index = charToIndex(c);
        if (!current->children[index]) {
            return -1;
        }
        current = current->children[index].get();
    }
    return current->maxWordIndex;
}

int WordFilter::charToIndex(char c) const {
    if (c == '{') {
        return 26;
    }
    return c - 'a';
}
