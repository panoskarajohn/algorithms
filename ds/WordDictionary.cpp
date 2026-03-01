#include "WordDictionary.h"

#include <array>
#include <vector>

struct WordDictionary::Node {
    std::array<std::unique_ptr<Node>, 26> children{};
    bool isTerminal = false;
};

WordDictionary::WordDictionary() : root(std::make_unique<Node>()) {}

WordDictionary::~WordDictionary() {}

void WordDictionary::addWord(const std::string &word) {
    Node *current = root.get();
    for (auto c : word) {
        int index = c - 'a';
        if (!current->children[index]) {
            current->children[index] = std::make_unique<Node>();
        }

        current = current->children[index].get();
    }
    current->isTerminal = true;
}

bool WordDictionary::dfs(int i, const Node *root, const std::string &word) const {
    if (!root) {
        return false;
    }

    if (i == word.size()) {
        return root->isTerminal;
    }

    const char currentChar = word[i];
    if (currentChar == '.') {
        for (const auto &child : root->children) {
            if (child && dfs(i + 1, child.get(), word)) {
                return true;
            }
        }
        return false;
    }

    const int index = currentChar - 'a';
    return dfs(i + 1, root->children[index].get(), word);
}

bool WordDictionary::search(const std::string &word) const {
    return dfs(0, root.get(), word);
}

bool WordDictionary::searchIterative(const std::string &word) const {
    std::vector<const Node *> currentNodes{root.get()};

    for (char c : word) {
        std::vector<const Node *> nextNodes;

        for (const Node *node : currentNodes) {
            if (!node) {
                continue;
            }

            if (c == '.') {
                for (const auto &child : node->children) {
                    if (child) {
                        nextNodes.push_back(child.get());
                    }
                }
                continue;
            }

            const int index = c - 'a';
            if (node->children[index]) {
                nextNodes.push_back(node->children[index].get());
            }
        }

        if (nextNodes.empty()) {
            return false;
        }

        currentNodes = std::move(nextNodes);
    }

    for (const Node *node : currentNodes) {
        if (node && node->isTerminal) {
            return true;
        }
    }

    return false;
}
