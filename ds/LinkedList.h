#include "Node.h"
#include <memory>
#pragma once

template <typename T> class LinkedList {

public:
  std::shared_ptr<Node<T>> head;
  std::shared_ptr<Node<T>> tail;

  LinkedList() : head(nullptr), tail(nullptr) {}

  void append(const T &value) {
    auto newNode = std::make_shared<Node<T>>(value);
    if (!head) {
      head = tail = newNode;
    } else {
      tail->next = newNode;
      newNode->prev = tail;
      tail = newNode;
    }
  }

  bool remove(const T &value) {
    auto current = head;
    while (current) {
      if (current->data != value) {
        current = current->next;
        continue;
      }

      auto prevNode = current->prev;
      auto nextNode = current->next;

      if (prevNode) {
        prevNode->next = nextNode;
      } else {
        head = nextNode;
      }

      if (nextNode) {
        nextNode->prev = prevNode;
      } else {
        tail = prevNode;
      }

      current = nextNode;
      return true;
    }
    return false;
  }

  T getHead() const {
    if (head) {
      return head->data;
    }
    throw std::runtime_error("List is empty");
  }
};
