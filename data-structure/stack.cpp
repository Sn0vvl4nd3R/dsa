#include <iostream>
#include <stdexcept>

template <typename T>
class Stack {
 private:
  struct Node {
    T data;
    Node* next;

    Node(const T& value, Node* next_node = nullptr)
      : data(value), next(next_node) {}
  };

  Node* top_node;
  int count;

 public:
  Stack() : top_node(nullptr), count(0) {}

  ~Stack() {
    while (top_node) {
      Node* temp = top_node;
      top_node = top_node->next;
      delete temp;
    }
  }

  void push(const T& value) {
    top_node = new Node(value, top_node);
    ++count;
  }

  void pop(void) {
    if (empty()) {
      throw std::runtime_error("The stack is empty.");
    }
    Node* temp = top_node;
    top_node = top_node->next;
    delete temp;
    --count;
  }

  T& top(void) {
    if (empty()) {
      throw std::runtime_error("The stack is empty.");
    }
    return top_node->data;
  }

  const T& top(void) const {
    if (empty()) {
      throw std::runtime_error("The stack is empty.");
    }
    return top_node->data;
  }

  bool empty(void) const {
    return top_node == nullptr;
  }

  int size(void) const {
    return count;
  }
};

int main(void) {
  return 0;
}
