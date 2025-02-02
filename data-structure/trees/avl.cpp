#include <iostream>

template <typename T>
class AVL {
 private:
  struct Node {
    T value;
    Node* left;
    Node* right;
    int height;

    Node(const T& value)
      : value(value), left(nullptr), right(nullptr), height(1) {}
  };

  Node* root;

  int get_height(Node* node) const {
    return node ? node->height : 0;
  }

  int get_balance(Node* node) const {
    return node ? get_height(node->left) - get_height(node->right) : 0;
  }

  void update_height(Node* node) {
    if (node) {
      node->height = std::max(get_height(node->left), get_height(node->right)) + 1;
    }
  }

  Node* right_rotate(Node* y) {
    Node* x = y->left;
    Node* t2 = x->right;

    x->right = y;
    y->left = t2;

    update_height(y);
    update_height(x);

    return x;
  }

  Node* left_rotate(Node* x) {
    Node* y = x->right;
    Node* t2 = y->left;

    y->left = x;
    x->right = t2;

    update_height(x);
    update_height(y);

    return y;
  }

  Node* balance(Node* node) {
    update_height(node);
    int balance_factor = get_balance(node);

    if (balance_factor > 1) {
      if (get_balance(node->left) < 0) {
        node->left = left_rotate(node->left);
      }
      return right_rotate(node);
    }

    if (balance_factor < -1) {
      if (get_balance(node->right) > 0) {
        node->right = right_rotate(node->right);
      }
      return left_rotate(node);
    }

    return node;
  }

  Node* insert(Node* node, const T& value) {
    if (node == nullptr) {
      return new Node(value);
    }
    if (value < node->value) {
      node->left = insert(node->left, value);
    } else if (value > node->value) {
      node->right = insert(node->right, value);
    } else {
      return node;
    }

    return balance(node);
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
      if (node->left == nullptr || node->right == nullptr) {
        Node* temp = node->left ? node->left : node->right;
        if (temp == nullptr) {
          temp = node;
          node = nullptr;
        } else {
          *node = *temp;
        }
        delete temp;
      } else {
        Node* temp = find_min(node->right);
        node->value = temp->value;
        node->right = remove(node->right, temp->value);
      }
    }

    if (node == nullptr) {
      return node;
    }

    return balance(node);
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
  AVL() : root(nullptr) {}

  ~AVL() {
    clear(root);
  }

  AVL(const AVL& other) = delete;
  AVL& operator=(const AVL& other) = delete;

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
    std::cout << '\n';
  }
};

int main(void) {
  return 0;
}
