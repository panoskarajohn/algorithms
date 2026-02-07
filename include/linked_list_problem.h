#pragma once

#include "Node.h"
#include <memory>

// Returns the middle node of a singly linked list.
// If the list has an even number of nodes, return the second middle node.
// If the list is empty, return nullptr.
std::shared_ptr<Node<int>> middleNode(const std::shared_ptr<Node<int>> &head);
