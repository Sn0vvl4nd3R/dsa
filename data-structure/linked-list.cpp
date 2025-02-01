#include <iostream>
#include <stdexcept>

template <typename T>
class LinkedList {
 private:
  struct Node {
    T data;
    Node* next;

    Node(const T& value, Node* next_node = nullptr)
      : data(value), next(next_node) {}
  };

  Node* head;
  Node* tail;
  int list_size;

  void copy_from(const LinkedList& other) {
    head = tail = nullptr;
    list_size = 0;
    Node* current = other.head;
    while (current) {
      push_back(current->data);
      current = current->next;
    }
  }

  void clear(void) {
    Node* current = head;
    while (current) {
      Node* next_node = current->next;
      delete current;
      current = next_node;
    }
    head = tail = nullptr;
    list_size = 0;
  }

 public:
  LinkedList() : head(nullptr), tail(nullptr), list_size(0) {}

  LinkedList(const LinkedList& other) {
    copy_from(other);
  }

  LinkedList& operator=(const LinkedList& other) {
    if (this != &other) {
      clear();
      copy_from(other);
    }
    return *this;
  }

  ~LinkedList() {
    clear();
  }

  void push_back(const T& value) {
    Node* new_node = new Node(value);
    if (!head) {
      head = tail = new_node;
    } else {
      tail->next = new_node;
      tail = new_node;
    }
    ++list_size;
  }

  void pop_front(void) {
    if (!head) {
      throw std::runtime_error("The list is empty.");
    }
    Node* temp = head;
    head = head->next;
    delete temp;
    --list_size;
    if (!head) {
      tail = nullptr;
    }
  }

  T& front(void) {
    if (!head) {
      throw std::runtime_error("The list is empty.");
    }
    return head->data;
  }

  const T& front(void) const {
    if (!head) {
      throw std::runtime_error("The list if empty.");
    }
    return head->data;
  }

  int size(void) const {
    return list_size;
  }

  bool empty(void) const {
    return list_size == 0;
  }

  void print() const {
    Node* current = head;
    while (current) {
      std::cout << current->data < ' ';
      current = current->next;
    }
    std::cout << '\n';
  }
};

int main(void) {
  return 0;
}
