#include <iostream>

template <typename T>
class SplayTree {
 private:
  struct Node {
    T value;
    Node* left;
    Node* right;
    Node* parent;

    Node(const T& value)
      : value(value), left(nullptr), right(nullptr), parent(nullptr) {}
  };

  Node* root;

  void rotate_left(Node* x) {
    Node* y = x->right;
    if (y) {
      x->right = y->left;
      if (y->left)
        y->left->parent = x;
      y->parent = x->parent;
    }
    if (x->parent == nullptr)
      root = y;
    else if (x == x->parent->left)
      x->parent->left = y;
    else
      x->parent->right = y;
    if (y)
      y->left = x;
    x->parent = y;
  }

  void rotate_right(Node* x) {
    Node* y = x->left;
    if (y) {
      x->left = y->right;
      if (y->right)
        y->right->parent = x;
      y->parent = x->parent;
    }
    if (x->parent == nullptr)
      root = y;
    else if (x == x->parent->left)
      x->parent->left = y;
    else
      x->parent->right = y;
    if (y)
      y->right = x;
    x->parent = y;
  }

  void splay(Node* x) {
    if (x == nullptr)
      return;
    while (x->parent != nullptr) {
      if (x->parent->parent == nullptr) {
        if (x->parent->left == x)
          rotate_right(x->parent);
        else
          rotate_left(x->parent);
      } else if (x->parent->left == x && x->parent->parent->left == x->parent) {
        rotate_right(x->parent->parent);
        rotate_right(x->parent);
      } else if (x->parent->right == x && x->parent->parent->right == x->parent) {
        rotate_left(x->parent->parent);
        rotate_left(x->parent);
      } else if (x->parent->left == x && x->parent->parent->right == x->parent) {
        rotate_right(x->parent);
        rotate_left(x->parent);
      } else {
        rotate_left(x->parent);
        rotate_right(x->parent);
      }
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
  SplayTree() : root(nullptr) {}

  ~SplayTree() {
    clear(root);
  }

  SplayTree(const SplayTree& other) = delete;
  SplayTree& operator=(const SplayTree& other) = delete;

  void insert(const T& value) {
    Node* z = root;
    Node* p = nullptr;

    while (z != nullptr) {
      p = z;
      if (value < z->value)
        z = z->left;
      else if (value > z->value)
        z = z->right;
      else {
        splay(z);
        return;
      }
    }

    Node* new_node = new Node(value);
    new_node->parent = p;

    if (p == nullptr)
      root = new_node;
    else if (value < p->value)
      p->left = new_node;
    else
      p->right = new_node;

    splay(new_node);
  }

  bool search(const T& value) {
    Node* z = root;
    Node* last = nullptr;
    while (z != nullptr) {
      last = z;
      if (value < z->value)
        z = z->left;
      else if (value > z->value)
        z = z->right;
      else {
        splay(z);
        return true;
      }
    }
    if (last != nullptr)
      splay(last);
    return false;
  }

  void remove(const T& value) {
    if (!search(value))
      return;

    Node* toDelete = root;

    if (root->left == nullptr) {
      root = root->right;
      if (root)
        root->parent = nullptr;
    } else {
      Node* left_subtree = root->left;
      left_subtree->parent = nullptr;
      Node* max_node = left_subtree;
      while (max_node->right != nullptr)
        max_node = max_node->right;
      splay(max_node);
      max_node->right = root->right;
      if (max_node->right)
        max_node->right->parent = max_node;
      root = max_node;
    }
    delete toDelete;
  }

  void in_order_traversal(void) const {
    inOrder(root);
    std::cout << "\n";
  }
};

int main(void) {
  return 0;
}

