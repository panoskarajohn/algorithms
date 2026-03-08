#include "WordFilter.h"
#include <array>

struct WordFilter::Node {
    std::array<std::unique_ptr<Node>, 26> children{};
    bool isTerminal = false;
    int wordIndex = -1;
    char data = '\0';
};

WordFilter::WordFilter(const std::vector<std::string> &words) : root(std::make_unique<Node>()) {
    int counter = 0;
    for (auto &word : words) {
        WordFilter::Node *current = root.get();
        for (auto c : word) {
            int index = c - 'a';
            if (!current->children[index]) {
                current->children[index] = std::make_unique<WordFilter::Node>();
                current->children[index].get()->data = c;
            }
            current = current->children[index].get();
        }
        current->isTerminal = true;
        current->wordIndex = counter;
        counter++;
    }
}

WordFilter::~WordFilter() {}

int WordFilter::dfs(std::string suffix, int suffixIndex, Node *root) {
    if (!root) {
        return -1;
    }

    if (suffixIndex >= suffix.length()) {
        return -1;
    }
    char currentChar = suffix[suffixIndex];
    int index = currentChar - 'a';

    int max = -1;
    for (const auto &child : root->children) {
        int copySuffixIndex = suffixIndex;
        max = std::max(dfs(suffix, copySuffixIndex, child.get()), max);
        if (root->children[index]) {
            max = std::max(dfs(suffix, ++copySuffixIndex, root->children[index].get()), max);
        }
    }

    if (root->children[index] && root->children[index]->isTerminal &&
        suffixIndex == suffix.length() - 1) { // we found a solution

        auto wordIndex = root->children[index]->wordIndex;
        return std::max(wordIndex, max);
    }
    return max;
}

int WordFilter::f(std::string prefix, std::string suffix) {
    Node *current = root.get();
    for (const auto &c : prefix) {
        int index = c - 'a';
        if (!current->children[index]) {
            return -1;
        }

        current = current->children[index].get();
    }
    return dfs(suffix, 0, current);
}
