#include "PrefixTree.h"
#include <array>
#include <stack>
#include <utility>

std::vector<std::pair<int, int>> getPositions(const std::vector<std::vector<char>> &board, int posY,
                                              int posX) {
    std::vector<std::pair<int, int>> result{};
    int height = board.size();
    int width = board[0].size();
    const std::vector<std::pair<int, int>> directions{
        {-1, 0}, // up
        {1, 0},  // down
        {0, 1},  // right
        {0, -1}  // left
    };

    for (const auto &[dy, dx] : directions) {
        int newY = posY - dy;
        int newX = posX - dx;

        if (newY >= 0 && newY < height && newX >= 0 && newX < width) {
            result.emplace_back(newY, newX);
        }
    }

    return result;
}

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

std::vector<std::string>
PrefixTree::searchWordsInBoard(const std::vector<std::vector<char>> &board) {
    std::vector<std::string> result{};
    std::set<std::pair<int, int>> visited{};

    int height = board.size();
    int width = board[0].size();

    for (int row = 0; row < height; row++) {
        for (int col = 0; col < width; col++) {
            checkPosition(visited, result, board, row, col);
        }
    }

    return result;
}

void PrefixTree::checkPosition(std::set<std::pair<int, int>> &visited,
                               std::vector<std::string> &result,
                               const std::vector<std::vector<char>> &board, int row, int col) {
    Node *current = root.get();
    std::set<std::pair<int, int>> localVisited{};
    std::stack<std::pair<int, int>> stack{};
    stack.push({row, col});
    std::string s;
    s.reserve(100); // good size for most of the leetcode cases

    while (!stack.empty()) {
        auto [currentRow, currentCol] = stack.top();
        stack.pop();

        if (visited.contains({currentRow, currentCol})) {
            continue;
        }

        char currentChar = board[currentRow][currentCol];
        int index = currentChar - 'a';

        if (!current->children[index]) {
            continue;
        }

        localVisited.insert({currentRow, currentCol});
        s += currentChar;

        current = current->children[index].get();
        if (current->isTerminal) {
            visited.insert(localVisited.begin(), localVisited.end());
            result.emplace_back(s);
        }
        // push to the stack
        for (auto [posRow, posCol] : getPositions(board, currentRow, currentCol)) {
            stack.push({posRow, posCol});
        }
    }
}

PrefixTree::~PrefixTree() {}
