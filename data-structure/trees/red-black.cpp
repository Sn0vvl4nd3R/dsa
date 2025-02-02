#include <iostream>

template <typename T>
class RBTree {
 private:
  enum Color { RED, BLACK };

  struct Node {
    T value;
    Color color;
    Node* left;
    Node* right;
    Node* parent;

    Node(const T& value)
      : value(value), color(RED), left(nullptr), right(nullptr), parent(nullptr) {}
  };

  Node* root;
  Node* NIL;

  void initNIL(void) {
    NIL = new Node(T());
    NIL->color = BLACK;
    NIL->left = NIL->right = NIL->parent = nullptr;
  }

  void left_rotate(Node* x) {
    Node* y = x->right;
    x->right = y->left;
    if (y->left != NIL) {
      y->left->parent = x;
    }
    y->parent = x->parent;
    if (x->parent == NIL) {
      root = y;
    } else if (x == x->parent->left) {
      x->parent->left = y;
    } else {
      x->parent->right = y;
    }
    y->left = x;
    x->parent = y;
  }

  void right_rotate(Node* y) {
    Node* x = y->left;
    y->left = x->right;
    if (x->right != NIL) {
      x->right->parent = y;
    }
    x->parent = y->parent;
    if (y->parent == NIL) {
      root = x;
    } else if (y == y->parent->right) {
      y->parent->right = x;
    } else {
      y->parent->left = x;
    }
    x->right = y;
    y->parent = x;
  }

  void insert_node(Node* z) {
    while (z->parent->color == RED) {
      if (z->parent == z->parent->parent->left) {
        Node* y = z->parent->parent->right;
        if (y->color == RED) {
          z->parent->color = BLACK;
          y->color = BLACK;
          z->parent->parent->color = RED;
          z = z->parent->parent;
        } else {
          if (z == z->parent->right) {
            z = z->parent;
            left_rotate(z);
          }
          z->parent->color = BLACK;
          z->parent->parent->color = RED;
          right_rotate(z->parent->parent);
        }
      } else {
        Node* y = z->parent->parent->left;
        if (y->color == RED) {
          z->parent->color = BLACK;
          y->color = BLACK;
          z->parent->parent->color = RED;
          z = z->parent->parent;
        } else {
          if (z == z->parent->left) {
            z = z->parent;
            right_rotate(z);
          }
          z->parent->color = BLACK;
          z->parent->parent->color = RED;
          left_rotate(z->parent->parent);
        }
      }
    }
    root->color = BLACK;
  }

  void transplant(Node* u, Node* v) {
    if (u->parent == NIL) {
      root = v;
    } else if (u == u->parent->left) {
      u->parent->left = v;
    } else {
      u->parent->right = v;
    }
    v->parent = u->parent;
  }

  Node* minimum(Node* node) const {
    while (node->left != NIL) {
      node = node->left;
    }
    return node;
  }

  void delete_fixup(Node* x) {
    while (x != root && x->color == BLACK) {
      if (x == x->parent->left) {
        Node* w = x->parent->right;
        if (w->color == RED) {
          w->color = BLACK;
          x->parent->color = RED;
          left_rotate(x->parent);
          w = x->parent->right;
        }
        if (w->left->color == BLACK && w->right->color == BLACK) {
          w->color = RED;
          x = x->parent;
        } else {
          if (w->right->color == BLACK) {
            w->left->color = BLACK;
            w->color = RED;
            right_rotate(w);
            w = x->parent->right;
          }
          w->color = x->parent->color;
          x->parent->color = BLACK;
          w->right->color = BLACK;
          left_rotate(x->parent);
          x = root;
        }
      } else {
        Node* w = x->parent->left;
        if (w->color == RED) {
          w->color = BLACK;
          x->parent->color = RED;
          right_rotate(x->parent);
          w = x->parent->left;
        }
        if (w->right->color == BLACK && w->left->color == BLACK) {
          w->color = RED;
          x = x->parent;
        } else {
          if (w->left->color == BLACK) {
            w->right->color = BLACK;
            w->color = RED;
            left_rotate(w);
            w = x->parent->left;
          }
          w->color = x->parent->color;
          x->parent->color = BLACK;
          w->left->color = BLACK;
          right_rotate(x->parent);
          x = root;
        }
      }
    }
    x->color = BLACK;
  }

  void in_order(Node* node) const {
    if (node != NIL) {
      in_order(node->left);
      std::cout << node->value << ' ';
      in_order(node->right);
    }
  }

  void clear(Node* node) {
    if (node != NIL) {
      clear(node->left);
      clear(node->right);
      delete node;
    }
  }

 public:
  RBTree() {
    initNIL();
    root = NIL;
  }

  ~RBTree() {
    clear(root);
    delete NIL;
  }

  RBTree(const RBTree& other) = delete;
  RBTree& operator=(const RBTree& other) = delete;

  void insert(const T& value) {
    Node* z = new Node(value);
    z->left = z->right = z->parent = NIL;

    Node* y = NIL;
    Node* x = root;
    while (x != NIL) {
      y = x;
      if (z->value < x->value)
        x = x->left;
      else if (z->value > x->value)
        x = x->right;
      else {
        delete z;
        return;
      }
    }
    z->parent = y;
    if (y == NIL)
      root = z;
    else if (z->value < y->value)
      y->left = z;
    else
      y->right = z;

    z->color = RED;
    insertFixup(z);
  }

  bool search(const T& value) const {
    Node* current = root;
    while (current != NIL) {
      if (value == current->value)
        return true;
      else if (value < current->value)
        current = current->left;
      else
        current = current->right;
    }
    return false;
  }

  void remove(const T& value) {
    Node* z = root;
    while (z != NIL) {
      if (z->value == value)
        break;
      else if (value < z->value)
        z = z->left;
      else
        z = z->right;
    }
    if (z == NIL)
      return;

    Node* y = z;
    Node* x;
    Color originalColor = y->color;
    if (z->left == NIL) {
      x = z->right;
      transplant(z, z->right);
    } else if (z->right == NIL) {
      x = z->left;
      transplant(z, z->left);
    } else {
      y = minimum(z->right);
      originalColor = y->color;
      x = y->right;
      if (y->parent == z) {
        x->parent = y;
      } else {
        transplant(y, y->right);
        y->right = z->right;
        y->right->parent = y;
      }
      transplant(z, y);
      y->left = z->left;
      y->left->parent = y;
      y->color = z->color;
    }
    delete z;
    if (originalColor == BLACK) {
      deleteFixup(x);
    }
  }

  void in_order_traversal(void) const {
    inOrder(root);
    std::cout << "\n";
  }
};

int main(void) {
  return 0;
}

