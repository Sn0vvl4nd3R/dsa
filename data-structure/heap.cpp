#include <iostream>
#include <stdexcept>

template <typename T>
class Heap {
 private:
  T* data;
  int heap_size;
  int capacity;

  void resize(int new_capacity) {
    T* new_data = new T[new_capacity];
    for (int i = 0; i < heap_size; i++) {
      new_data[i] = data[i];
    }
    delete[] data;
    data = new_data;
    capacity = new_data;
  }

  void heapify_up(int index) {
    while (index > 0) {
      int parent = (index - 1) / 2;
      if (data[index] < data[parent]) {
        T temp = data[index];
        data[index] = data[parent];
        data[parent] = temp;
        index = parent;
      } else {
        break;
      }
    }
  }

  void heapify_down(int index) {
    while (2 * index + 1 < heap_size) {
      int left_child = 2 * index + 1;
      int right_child = 2 * index + 2;
      int smallest = index;

      if (left_child < heap_size && data[left_child] < data[smallest]) {
        smallest = left_child;
      }
      if (right_child < heap_size && data[right_child] < data[smallest]) {
        smallest = right_child;
      }
      if (smallest == index) {
        break;
      }

      T temp = data[index];
      data[index] = data[smallest];
      data[smallest] = temp;
      index = smallest;
    }
  }

 public:
  Heap(int initial_capacity = 10)
    : heap_size(0), capacity(initial_capacity) {
    data = new T[capacity];
  }

  Heap(const Heap& other)
    : heap_size(other.heap_size), capacity(other.capacity) {
    data = new T[capacity];
    for (int i = 0; i < heap_size; i++) {
      data[i] = other.data[i];
    }
  }

  Heap& operator=(const Heap& other) {
    if (this != &other) {
      delete[] data;
      heap_size = other.heap_size;
      capacity = other.capacity;
      data = new T[capacity];
      for (int i = 0; i < heap_size; i++) {
        data[i] = other.data[i];
      }
    }
    return *this;
  }

  ~Heap() {
    delete[] data;
  }

  void push(const T& value) {
    if (heap_size == capacity) {
      resize(capacity * 2);
    }
    data[heap_size] = value;
    heapify_up(heap_size);
    ++heap_size;
  }

  void pop(void) {
    if (empty()) {
      throw std::runtime_error("The heap is empty.");
    }
    data[0] = data[heap_size - 1];
    --heap_size;
    heapify_down(0);
  }

  const T& top(void) const {
    if (empty()) {
      throw std::runtime_error("The heap is empty.");
    }
    return data[0];
  }

  bool empty(void) const {
    return heap_size == 0;
  }

  int size(void) const {
    return heap_size;
  }
};

int main(void) {
  return 0;
}
