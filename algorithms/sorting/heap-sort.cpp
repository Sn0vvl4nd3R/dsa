#include <iostream>
#include <vector>

template <typename T>
void Heapify(std::vector<T>& array, size_t n, size_t i) {
  size_t largest = i;
  size_t left = 2 * i + 1;
  size_t right = 2 * i + 2;

  if (left < n && array[left] > array[largest]) {
    largest = left;
  }
  if (right < n && array[right] > array[largest]) {
    largest = right;
  }
  if (largest != i) {
    std::swap(array[i], array[largest]);
    Heapify(array, n, largest);
  }
}

template <typename T>
void HeapSort(std::vector<T>& array) {
  for (int i = static_cast<int>(array.size()) / 2 - 1; i >= 0; i--) {
    Heapify(array, array.size(), i);
  }

  for (int i = static_cast<int>(array.size()) - 1; i > 0; i--) {
    std::swap(array[0], array[i]);
    Heapify(array, i, 0);
  }
}

int main(void) {
  std::vector<int> array;
  int value = 0;

  std::cout << "Enter elements (enter 0 to finish):\n";
  while (std::cin >> value && value != 0) {
    array.push_back(value);
  }

  HeapSort(array);

  for (auto x : array) {
    std::cout << x << ' ';
  }
  std::cout << '\n';

  return 0;
}
