#include <iostream>
#include <vector>

template <typename T>
void SelectionSort(std::vector<T>& array) {
  for (size_t i = 0; i < array.size(); i++) {
    size_t min_index = i;
    for (size_t j = i + 1; j < array.size(); j++) {
      if (array[j] < array[min_index]) {
        min_index = j;
      }
    }
    if (min_index != i) {
      std::swap(array[i], array[min_index]);
    }
  }
}

int main(void) {
  std::vector<int> array;
  int value = 0;

  std::cout << "Enter elements (enter 0 to finish):\n";
  while (std::cin >> value && value != 0) {
    array.push_back(value);
  }

  SelectionSort(array);

  for (auto x : array) {
    std::cout << x << ' ';
  }
  std::cout << '\n';

  return 0;
}
