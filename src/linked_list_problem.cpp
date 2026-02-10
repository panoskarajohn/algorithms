#include "linked_list_problem.h"
#include <map>
#include <stack>
#include <stdexcept>

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

int maxTwinSum(const std::shared_ptr<Node<int>> &head) {
    std::stack<std::shared_ptr<Node<int>>> stack;

    auto temp = head;
    while (temp != nullptr) {
        stack.push(temp);
        temp = temp->next;
    }

    int n = stack.size();
    int i = 0;
    int max = 0;
    temp = head;

    while (i != n / 2 && temp != nullptr) {
        int value = temp->data;
        auto popped = stack.top()->data;
        stack.pop();
        max = std::max(value + popped, max);
        temp = temp->next;
        i++;
    }

    return max;
}

bool hasCycle(const std::shared_ptr<Node<int>> &head) {

    if (head == nullptr) {
        return false;
    }

    auto slow = head;
    auto fast = head;

    while (fast != nullptr && fast->next != nullptr) {
        slow = slow->next;
        fast = fast->next->next;
        if (slow == fast) {
            return true;
        }
    }

    return false;
}

std::shared_ptr<Node<int>> detectCycle(const std::shared_ptr<Node<int>> &head) {
    if (head == nullptr) {
        return nullptr;
    }

    auto slow = head;
    auto fast = head;

    while (fast != nullptr && fast->next != nullptr) {
        slow = slow->next;
        fast = fast->next->next;

        if (slow == fast) {
            // cycle detected
            slow = head;
            while (slow != fast) {
                slow = slow->next;
                fast = fast->next;
            }
            return slow;
        }
    }
    return nullptr;
}
