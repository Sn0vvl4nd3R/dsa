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
      int new_capacity = (_capacity = 0 ? 1 : _capacity * 2);
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
};

int main(void) {
  Array<int> array;
  int value = 0;

  std::cout << "Enter the elements (enter 0 to exit):\n";
  while (std::cin >> value && value != 0) {
    array.push_back(value);
  }

  std::cout << "The elements of the array: ";
  for (int i = 0; i < array.size(); i++) {
    std::cout << array[i] << ' ';
  }
  std::cout << "\nThe size of the array: " << array.size();
  std::cout << "\nThe capacity of the array: " << array.capacity() << '\n';

  return 0;
}
