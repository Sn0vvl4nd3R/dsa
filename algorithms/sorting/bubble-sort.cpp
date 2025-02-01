#include <iostream>
#include <vector>

template <typename T>
void BubbleSort(std::vector<T>& array) {
  bool is_swapped;
  for (size_t i = 0; i < array.size(); i++) {
    is_swapped = false;
    for (size_t j = 0; j < array.size() - i - 1; j++) {
      if (array[j] > array[j + 1]) {
        std::swap(array[j], array[j + 1]);
        is_swapped = true;
      }
    }
    if (!is_swapped) {
      break;
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

  BubbleSort(array);

  for (auto x : array) {
    std::cout << x << ' ';
  }
  std::cout << '\n';

  return 0;
}
