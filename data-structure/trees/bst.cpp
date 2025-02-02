#include <iostream>

template <typename T>
class BST {
 private:
  struct Node {
    T value;
    Node* left;
    Node* right;

    Node(const T& value)
      : value(value), left(nullptr), right(nullptr) {}
  };

  Node* root;

  void insert(Node*& node, const T& value) {
    if (node == nullptr) {
      node = new Node(value);
    } else if (value < node->value) {
      insert(node->left, value);
    } else if (value > node->value) {
      insert(node->right, value);
    }
  }

  bool search(Node* node, const T& value) const {
    if (node == nullptr) {
      return false;
    } else if (node->value == value) {
      return true;
    } else if (value < node->value) {
      return search(node->left, value);
    } else {
      return search(node->right, value);
    }
  }

  Node* find_min(Node* node) const {
    while (node && node->left != nullptr) {
      node = node->left;
    }
    return node;
  }

  Node* remove(Node* node, const T& value) {
    if (node == nullptr) {
      return node;
    }
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
        Node* temp = find_min(node->right);
        node->value = temp->value;
        node->right = remove(node->right, temp->value);
      }
    }
    return node;
  }

  void clear(Node* node) {
    if (node != nullptr) {
      clear(node->left);
      clear(node->right);
      delete node;
    }
  }

  void in_order(Node* node) const {
    if (node != nullptr) {
      in_order(node->left);
      std::cout << node->value << ' ';
      in_order(node->right);
    }
  }

 public:
  BST() : root(nullptr) {}

  ~BST() {
    clear(root);
  }

  BST(const BST& other) = delete;
  BST& operator=(const BST& other) = delete;

  void insert(const T& value) {
    insert(root, value);
  }

  bool search(const T& value) const {
    return search(root, value);
  }

  void remove(const T& value) {
    root = remove(root, value);
  }

  void in_order_traversal(void) const {
    in_order(root);
    std::cout << '\n';
  }
};

int main(void) {
  return 0;
}
