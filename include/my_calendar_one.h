#pragma once

#include <memory>

// LeetCode 729 – My Calendar I
// Both operations run in O(log(10^9)) ≈ 30 steps.

class MyCalendarOne {
  public:
    MyCalendarOne();
    bool book(int start, int end);

  private:
    struct Node {
        bool booked = false;
        std::shared_ptr<Node> left;
        std::shared_ptr<Node> right;
    };

    static const int LOW = 0;
    static const int HIGH = 1'000'000'000;

    std::shared_ptr<Node> root;

    bool query(std::shared_ptr<Node> node, int low, int high, int querylow, int queryhigh);
    void update(std::shared_ptr<Node> node, int low, int high, int updatelow, int updatehigh);
};
