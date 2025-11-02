#pragma once
#include <memory>

template <typename T> class Node {
public:
  T data;
  std::shared_ptr<Node<T>> next;
  std::shared_ptr<Node<T>> prev;

  Node(const T &value) : data(value), next(nullptr), prev(nullptr) {}
};
