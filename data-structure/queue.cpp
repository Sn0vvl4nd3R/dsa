#include <iostream>
#include <stdexcept>

template <typename T>
class Queue {
 private:
  struct Node {
    T data;
    Node* next;

    Node(const T& value, Node* next_node = nullptr)
      : data(value), next(next_node) {}
  };

  Node* head;
  Node* tail;
  int count;

 public:
  Queue() : head(nullptr), tail(nullptr), count(0) {}

  ~Queue() {
    while (head) {
      Node* temp = head;
      head = head->next;
      delete temp;
    }
  }

  void push(const T& value) {
    Node* new_node = new Node(value);
    if (empty()) {
      head = tail = new_node;
    } else {
      tail->next = new_node;
      tail = new_node;
    }
    ++count;
  }

  void pop(void) {
    if (empty()) {
      throw std::runtime_error("The queue is empty.");
    }
    Node* temp = head;
    head = head->next;
    delete temp;
    --count;
    if (head == nullptr) {
      tail = nullptr;
    }
  }

  T& front(void) {
    if (empty()) {
      throw std::runtime_error("The queue is empty.");
    }
    return head->data;
  }

  const T& front(void) const {
    if (empty()) {
      throw std::runtime_error("The queue is empty.");
    }
    return head->data;
  }


  T& back(void) {
    if (empty()) {
      throw std::runtime_error("The queue is empty.");
    }
    return tail->data;
  }


  const T& back(void) const {
    if (empty()) {
      throw std::runtime_error("The queue is empty.");
    }
    return tail->data;
  }

  bool empty(void) const {
    return count == 0;
  }

  int size(void) const {
    return count;
  }
};

int main(void) {
  return 0;
}
