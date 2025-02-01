#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>

template <typename T>
size_t PartitionLomuto(std::vector<T>& array, size_t low, size_t high) {
  size_t pivot_index = low + rand() % (high - low + 1);
  std::swap(array[pivot_index], array[high]);
  T pivot_value = array[high];

  size_t store_index = low;
  for (size_t i = low; i < high; i++) {
    if (array[i] < pivot_value) {
      std::swap(array[i], array[store_index]);
      store_index++;
    }
  }

  std::swap(array[store_index], array[high]);
  return store_index;
}

template <typename T>
size_t PartitionHoare(std::vector<T>& array, int low, int high) {
  int pivot_index = low + rand() % (high - low + 1);
  T pivot = array[pivot_index];
  std::swap(array[pivot_index], array[low]);

  int i = low - 1;
  int j = high + 1;

  while (true) {
    do {
      i++;
    } while (array[i] < pivot);

    do {
      j--;
    } while (array[j] > pivot);

    if (i >= j) {
      return j;
    }

    std::swap(array[i], array[j]);
  }
}

template <typename T>
void QuickSortRecursionLomuto(std::vector<T>& array, int low, int high) {
  if (low < high) {
    size_t p = PartitionLomuto(array, low, high);
    QuickSortRecursion(array, low, p - 1);
    QuickSortRecursion(array, p + 1, high);
  }
}

template <typename T>
void QuickSortRecursionHoare(std::vector<T>& array, int low, int high) {
  if (low < high) {
    size_t p = PartitionHoare(array, low, high);
    QuickSortRecursionHoare(array, low, p);
    QuickSortRecursionHoare(array, p + 1, high);
  }
}

template <typename T>
void QuickSort(std::vector<T>& array) {
  if (array.size() <= 1) {
    return;
  }
  srand(static_cast<unsigned>(time(nullptr)));
  QuickSortRecursionHoare(array, 0, array.size() - 1);
}

int main(void) {
  std::vector<int> array;
  int value = 0;

  std::cout << "Enter elements (enter 0 to finish):\n";
  while (std::cin >> value && value != 0) {
    array.push_back(value);
  }

  QuickSort(array);

  for (auto x : array) {
    std::cout << x << ' ';
  }
  std::cout << '\n';

  return 0;
}
