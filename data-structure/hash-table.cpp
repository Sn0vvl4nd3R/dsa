#include <filesystem>
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
      _size=  other._size;
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

template <typename K, typename V>
class HashTable {
 private:
  struct KeyValuePair {
    K key;
    V value;

    KeyValuePair(const K& k, const V& v)
      : key(k), value(v) {}
  };

  Array < Array<KeyValuePair> > _buckets;

  int _size;
  int _capacity;

  unsigned int hash_function(const K& key) const {
    return static_cast<unsigned int>(key < 0 ? -key : key);
  }

 public:
  HashTable(int capacity = 10)
    : _size(0), _capacity(capacity) {
    _buckets.resize_external(_capacity);
    for (int i = 0; i < _capacity; i++) {
    }
  }

  ~HashTable() {
  }

  HashTable(const HashTable& other)
    : _size(other._size), _capacity(other._capacity) {
    _buckets = other._buckets;
  }

  HashTable& operator=(const HashTable& other) {
    if (this != &other) {
      _size = other._size;
      _capacity = other._capacity;
      _buckets = other._buckets;
    }
    return *this;
  }

  void insert(const K& key, const V& value) {
    unsigned int hash_value = hash_function(key);
    int index = hash_value % _capacity;

    Array<KeyValuePair>& bucket = _buckets[index];

    for (int i = 0; i < bucket.size(); i++) {
      if (bucket[i].key == key) {
        bucket[i].value = value;
        return;
      }
    }

    bucket.push_back(KeyValuePair(key, value));
    _size++;
  }

  bool find(const K& key, V& out_value) const {
    unsigned int hash_value = hash_function(key);
    int index = hash_value % _capacity;

    const Array<KeyValuePair>& bucket = _buckets[index];
    for (int i = 0; i < bucket.size(); i++) {
      if (bucket[i].key == key) {
        out_value = bucket[i].value;
        return true;
      }
    }
    return false;
  }

  bool remove(const K& key) {
    unsigned int hash_value = hash_function(key);
    int index = hash_value % _capacity;

    Array<KeyValuePair>& bucket = _buckets[index];
    for (int i = 0; i < bucket.size(); i++) {
      if (bucket[i].key == key) {
        for (int j = i; j < bucket.size() - 1; j++) {
          bucket[j] = bucket[j + 1];
        }
        bucket.pop_back();
        _size--;
        return true;
      }
    }
    return false;
  }

  int size(void) const {
    return _size;
  }

  int capacity(void) const {
    return _capacity;
  }
};

int main(void) {
  return 0;
}
