#include <iostream>

template <typename T>
class Array {
 private:
  T* data;
  int _size;
  int _capacity;

  void resize(int new_capacity) {
    T* new_data = new T[new_capacity];
    for (int i = 0; i < _size; i++) {
      new_data[i] = data[i];
    }
    delete[] data;
    data = new_data;
    _capacity = new_capacity;
  }

 public:
  Array() : data(nullptr), _size(0), _capacity(0) {}

  ~Array() {
    delete[] data;
  }

  Array(const Array& other)
    : data(nullptr), _size(other._size), _capacity(other._capacity) {
    if (_capacity > 0) {
      data = new T[_capacity];
      for (int i = 0; i < _size; i++) {
        data[i] = other.data[i];
      }
    }
  }

  Array& operator=(const Array& other) {
    if (this != &other) {
      delete[] data;
      _size = other._size;
      _capacity = other._capacity;
      if (_capacity > 0) {
        data = new T[_capacity];
        for (int i = 0; i < _size; i++) {
          data[i] = other.data[i];
        }
      } else {
        data = nullptr;
      }
    }
    return *this;
  }

  void push_back(const T& value) {
    if (_size == _capacity) {
      int new_capacity = (_capacity == 0 ? 1 : _capacity * 2);
      resize(new_capacity);
    }
    data[_size++] = value;
  }

  void pop_back(void) {
    if (_size > 0) {
      --_size;
    }
  }

  T& operator[](int index) {
    return data[index];
  }

  const T& operator[](int index) const {
    return data[index];
  }

  int size(void) const {
    return _size;
  }

  int capacity(void) const {
    return _capacity;
  }

  void resize_external(int new_capacity) {
    resize(new_capacity);
    _size = new_capacity;
  }
};

class DisjointSet {
 private:
  Array<int> parent;
  Array<int> rank;
  int _size;

 public:
  DisjointSet(int n) : _size(n) {
    parent.resize_external(n);
    rank.resize_external(n);

    for (int i = 0; i < n; i++) {
      parent[i] = i;
      rank[i] = 0;
    }
  }

  ~DisjointSet() {
  }

  int find(int x) {
    if (parent[x] != x) {
      parent[x] = find(parent[x]);
    }
    return parent[x];
  }

  void union_set(int x, int y) {
    int rootX = find(x);
    int rootY = find(y);

    if (rootX != rootY) {
      if (rank[rootX] < rank[rootY]) {
        parent[rootX] = rootY;
      } else if (rank[rootX] > rank[rootY]) {
        parent[rootY] = rootX;
      } else {
        parent[rootY] = rootX;
        rank[rootX]++;
      }
    }
  }

  bool is_same_set(int x, int y) {
    return find(x) == find(y);
  }
};

int main(void) {
  return 0;
}
