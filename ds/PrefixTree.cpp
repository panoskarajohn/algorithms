#include "PrefixTree.h"
#include <array>
#include <utility>

struct PrefixTree::Node {
    std::array<std::unique_ptr<Node>, 26> children{};
    bool isTerminal = false;
};

PrefixTree::PrefixTree() : root(std::make_unique<Node>()) {}

void PrefixTree::insert(const std::string &word) {
    PrefixTree::Node *current = root.get();
    for (auto c : word) {
        int index = c - 'a';
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

std::vector<std::string>
PrefixTree::searchWordsInBoard(const std::vector<std::vector<char>> &board) {
    if (board.empty() || board[0].empty()) {
        return {};
    }

    std::set<std::string> found{};
    std::vector<std::vector<bool>> visited(board.size(), std::vector<bool>(board[0].size(), false));
    std::string current{};

    const int height = static_cast<int>(board.size());
    const int width = static_cast<int>(board[0].size());

    for (int row = 0; row < height; row++) {
        for (int col = 0; col < width; col++) {
            checkPosition(board, row, col, root.get(), visited, current, found);
        }
    }

    return {found.begin(), found.end()};
}

void PrefixTree::checkPosition(const std::vector<std::vector<char>> &board, int row, int col,
                               const Node *node, std::vector<std::vector<bool>> &visited,
                               std::string &current, std::set<std::string> &found) const {
    if (visited[row][col]) {
        return;
    }

    const char c = board[row][col];
    const int index = c - 'a';
    if (!node->children[index]) {
        return;
    }

    const Node *next = node->children[index].get();
    visited[row][col] = true;
    current.push_back(c);

    if (next->isTerminal) {
        found.insert(current);
    }

    static constexpr std::array<std::pair<int, int>, 4> directions{
        std::pair{-1, 0},
        std::pair{1, 0},
        std::pair{0, -1},
        std::pair{0, 1},
    };

    const int height = static_cast<int>(board.size());
    const int width = static_cast<int>(board[0].size());

    for (const auto [dr, dc] : directions) {
        const int nr = row + dr;
        const int nc = col + dc;
        if (nr < 0 || nr >= height || nc < 0 || nc >= width) {
            continue;
        }
        checkPosition(board, nr, nc, next, visited, current, found);
    }

    current.pop_back();
    visited[row][col] = false;
}

PrefixTree::~PrefixTree() {}
