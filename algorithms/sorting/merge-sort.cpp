#include <iostream>
#include <vector>

template <typename T>
void Merge(std::vector<T>& array, size_t left, size_t mid, size_t right) {
  size_t n1 = mid - left + 1;
  size_t n2 = right - mid;

  std::vector<T> L(n1), R(n2);
  for (size_t i = 0; i < n1; i++) {
    L[i] = array[left + i];
  }
  for (size_t j = 0; j < n2; j++) {
    R[j] = array[mid + j + 1];
  }

  size_t i = 0, j = 0;
  size_t k = left;

  while (i < n1 && j < n2) {
    if (L[i] <= R[j]) {
      array[k] = L[i];
      i++;
    } else {
      array[k] = R[j];
      j++;
    }
    k++;
  }

  while (i < n1) {
    array[k++] = L[i++];
  }
  while (j < n2) {
    array[k++] = R[j++];
  }
}

template <typename T>
void MergeSortRecursion(std::vector<T>& array, size_t left, size_t right) {
  if (left < right) {
    size_t mid = left + (right - left) / 2;
    MergeSortRecursion(array, left, mid);
    MergeSortRecursion(array, mid + 1, right);
    Merge(array, left, mid, right);
  }
}

template <typename T>
void MergeSort(std::vector<T>& array) {
  if (array.empty()) {
    return;
  }
  MergeSortRecursion(array, 0, array.size() - 1);
}

int main(void) {
  std::vector<int> array;
  int value = 0;

  std::cout << "Enter elements (enter 0 to finish):\n";
  while (std::cin >> value && value != 0) {
    array.push_back(value);
  }

  MergeSort(array);

  for (auto x : array) {
    std::cout << x << ' ';
  }
  std::cout << '\n';

  return 0;
}
