#include "my_calendar_one.h"
MyCalendarOne::MyCalendarOne() { this->root = std::make_shared<MyCalendarOne::Node>(); }

// returns true if any part of the query is booked
bool MyCalendarOne::query(std::shared_ptr<Node> node, int low, int high, int querylow,
                          int queryhigh) {
    if (node == nullptr) {
        return false;
    }

    if (querylow >= high || queryhigh <= low) {
        return false;
    }

    if (node->booked) {
        return true;
    }

    int mid = low + (high - low) / 2;
    return (this->query(node->left, low, mid, querylow, queryhigh) ||
            this->query(node->right, mid + 1, high, querylow, queryhigh));
}

void MyCalendarOne::update(std::shared_ptr<Node> node, int low, int high, int updatelow,
                           int updatehigh) {
    if (updatelow >= high || updatehigh <= low) {
        return;
    }

    if (updatelow <= low && high <= updatehigh) {
        node->booked = true;
        return;
    }

    if (node->left == nullptr) {
        node->left = {};
    }

    if (node->right == nullptr) {
        node->right = {};
    }

    int mid = low + (high - low) / 2;
    this->update(node->left, low, mid, updatelow, updatehigh);
    this->update(node->right, mid + 1, high, updatelow, updatehigh);
}

bool MyCalendarOne::book(int start, int end) {
    if (this->query(this->root, 0, 1e9, start, end)) {
        return false;
    }
    this->update(this->root, 0, 1e9, start, end);
    return true;
    return false;
}
