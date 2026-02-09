#pragma once

#include "Node.h"
#include <memory>

// Returns the middle node of a singly linked list.
// If the list has an even number of nodes, return the second middle node.
// If the list is empty, return nullptr.
std::shared_ptr<Node<int>> middleNode(const std::shared_ptr<Node<int>> &head);

// Returns the maximum twin sum of a linked list with even length.
// A twin sum is defined as the sum of the i-th node from the start
// and the i-th node from the end.
// If the list is empty, return 0.
int maxTwinSum(const std::shared_ptr<Node<int>> &head);

// Returns true if a singly linked list contains a cycle, otherwise false.
bool hasCycle(const std::shared_ptr<Node<int>> &head);
