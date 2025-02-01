#include <iostream>
#include <vector>

template <typename T>
void ShellSort(std::vector<T>& array) {
  for (size_t gap = array.size() / 2; gap > 0; gap /= 2) {
    for (size_t i = gap; i < array.size(); i++) {
      T temp = array[i];
      size_t j = i;
      while (j >= gap && array[j - gap] > temp) {
        array[j] = array[j - gap];
        j -= gap;
      }
      array[j] = temp;
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

  ShellSort(array);

  for (auto x : array) {
    std::cout << x << ' ';
  }
  std::cout << '\n';

  return 0;
}
