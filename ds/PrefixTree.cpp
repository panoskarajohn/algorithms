#include "PrefixTree.h"

#include <array>
#include <stdexcept>
#include <utility>

struct PrefixTree::Node {
    std::array<std::unique_ptr<Node>, 26> children{};
    bool isTerminal = false;
};

PrefixTree::PrefixTree() : root(std::make_unique<Node>()) {}

void PrefixTree::insert(const std::string &word) {
    PrefixTree::Node *current = root.get();
    for (auto c : word) {
        int index = c - 'a'; // make sure we only pass lowercase chars
        if (!current->children[index]) {
            current->children[index] = std::make_unique<PrefixTree::Node>();
        }

        current = current->children[index].get();
    }
    current->isTerminal = true;
}

bool PrefixTree::startsWith(const std::string &prefix) const {
    PrefixTree::Node *current = root.get();
    for (const auto c : prefix) {
        int index = c - 'a';
        if (!current->children[index]) {
            return false;
        }
        current = current->children[index].get();
    }
    return true;
}

bool PrefixTree::search(const std::string &word) const {
    PrefixTree::Node *current = root.get();
    for (const auto c : word) {
        int index = c - 'a';
        if (!current->children[index]) {
            return false;
        }
        current = current->children[index].get();
    }
    return current->isTerminal;
}

PrefixTree::~PrefixTree() {}
