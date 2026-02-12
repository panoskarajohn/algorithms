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
    (void)word;
    throw std::logic_error("PrefixTree::insert is not implemented");
}

bool PrefixTree::startsWith(const std::string &prefix) const {
    (void)prefix;
    throw std::logic_error("PrefixTree::startsWith is not implemented");
}

PrefixTree::~PrefixTree() {}
