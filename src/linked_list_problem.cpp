#include "linked_list_problem.h"

std::shared_ptr<Node<int>> middleNode(const std::shared_ptr<Node<int>> &head) {
    if (head == nullptr) {
        return head;
    }

    auto slow = head;
    auto fast = head;
    while (fast != nullptr && fast->next != nullptr) {
        slow = slow->next;
        fast = fast->next->next;
    }

    return slow;
}
