#include <iostream>
#include <cstdlib>
#include <ctime>

template <typename T>
class Treap {
 private:
  struct Node {
    T value;
    int priority;
    Node* left;
    Node* right;

    Node(const T& value)
      : value(value), priority(std::rand()), left(nullptr), right(nullptr) {}
  };

  Node* root;

  Node* rotate_right(Node* y) {
    Node* x = y->left;
    y->left = x->right;
    x->right = y;
    return x;
  }

  Node* rotate_left(Node* x) {
    Node* y = x->right;
    x->right = y->left;
    y->left = x;
    return y;
  }

  Node* insert(Node* node, const T& value) {
    if (node == nullptr) {
      return new Node(value);
    }
    if (value < node->value) {
      node->left = insert(node->left, value);
      if (node->left->priority > node->priority) {
        node = rotate_right(node);
      }
    } else if (value > node->value) {
      node->right = insert(node->right, value);
      if (node->right->priority > node->priority) {
        node = rotate_left(node);
      }
    }
    return node;
  }

  bool search(Node* node, const T& value) const {
    if (node == nullptr) {
      return false;
    } else if (value == node->value) {
      return true;
    } else if (value < node->value) {
      return search(node->left, value);
    } else {
      return search(node->right, value);
    }
  }

  Node* remove(Node* node, const T& value) {
    if (node == nullptr)
      return node;
    if (value < node->value) {
      node->left = remove(node->left, value);
    } else if (value > node->value) {
      node->right = remove(node->right, value);
    } else {
      if (node->left == nullptr && node->right == nullptr) {
        delete node;
        node = nullptr;
      } else if (node->left == nullptr) {
        Node* temp = node;
        node = node->right;
        delete temp;
      } else if (node->right == nullptr) {
        Node* temp = node;
        node = node->left;
        delete temp;
      } else {
        if (node->left->priority > node->right->priority) {
          node = rotate_right(node);
          node->right = remove(node->right, value);
        } else {
          node = rotate_left(node);
          node->left = remove(node->left, value);
        }
      }
    }
    return node;
  }

  void in_order(Node* node) const {
    if (node != nullptr) {
      in_order(node->left);
      std::cout << node->value << ' ';
      in_order(node->right);
    }
  }

  void clear(Node* node) {
    if (node != nullptr) {
      clear(node->left);
      clear(node->right);
      delete node;
    }
  }

 public:
  Treap() : root(nullptr) {
    std::srand(std::time(nullptr));
  }

  ~Treap() {
    clear(root);
  }

  Treap(const Treap& other) = delete;
  Treap& operator=(const Treap& other) = delete;

  void insert(const T& value) {
    root = insert(root, value);
  }

  void remove(const T& value) {
    root = remove(root, value);
  }

  bool search(const T& value) const {
    return search(root, value);
  }

  void in_order_traversal(void) const {
    in_order(root);
    std::cout << "\n";
  }
};

int main(void) {
  return 0;
}
