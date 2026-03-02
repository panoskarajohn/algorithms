#include "PrefixTree.h"
#include <array>

std::vector<char> getMatrixBoardNeighbors(int posX, int posY,
                                          const std::vector<std::vector<char>> &board) {
    int height = board.size();
    int width = board[0].size();
    auto result = std::vector<char>{};

    if (posX >= width || posX < 0) {
        throw std::invalid_argument("out of range posX");
    }

    if (posY >= height || posY < 0) {
        throw std::invalid_argument("out of range posY");
    }

    int topX = posX;
    int topY = posY--;

    if (topY > 0) {
        result.push_back(board[topY][topX]);
    }

    int leftX = posX--;
    int leftY = posY;

    if (leftX > 0) {
        result.push_back(board[leftY][leftX]);
    }

    int rightX = posX++;
    int rightY = posY;

    if (rightX < width) {
        result.push_back(board[rightY][rightX]);
    }

    int bottomX = posX;
    int bottomY = posY++;

    if (bottomY < height) {
        result.push_back(board[bottomY][bottomX]);
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
    std::vector<std::string> result = {};
    // we have already setup our words in the trie
    // we should dfs the board and check our trie if it contains the word
    // this would be easier recursive but let's try to do it iterative

    // we need a visited so we don't iterate forever...?
    return result;
}

PrefixTree::~PrefixTree() {}
