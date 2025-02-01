#include <iostream>
#include <vector>

template <typename T>
void InsertionSort(std::vector<T>& array) {
  for (size_t i = 1; i < array.size(); i++) {
    T key = array[i];
    int j = static_cast<int>(i) - 1;

    while (j >= 0 && array[j] > key) {
      array[j + 1] = array[j];
      j--;
    }

    array[j + 1] = key;
  }
}

int main(void) {
  std::vector<int> array;
  int value = 0;

  std::cout << "Enter elements (enter 0 to finish):\n";
  while (std::cin >> value && value != 0) {
    array.push_back(value);
  }

  InsertionSort(array);

  for (auto x : array) {
    std::cout << x << ' ';
  }
  std::cout << '\n';

  return 0;
}
