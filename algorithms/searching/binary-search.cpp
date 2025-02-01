#include <iostream>
#include <vector>
#include <optional>
#include <algorithm>

template <typename T>
std::optional<size_t> BinarySearch(const std::vector<T>& array, const T& target) {
  size_t left = 0;
  size_t right = array.size();

  while (left < right) {
    size_t mid = left + (right - left) / 2;
    if (array[mid] == target) {
      return mid;
    } else if (array[mid] < target) {
      left = mid + 1;
    } else {
      right = mid;
    }
  }
  return std::nullopt;
}

int main(void) {
  std::vector<int> array;
  int value = 0;

  std::cout << "Enter elements (enter -1 to finish):\n";
  while (std::cin >> value && value != -1) {
    array.push_back(value);
  }

  std::sort(array.begin(), array.end());
  for (size_t i = 0; i < array.size(); i++) {
    std::cout << array[i] << ' ';
  }
  std::cout << '\n';

  int x = 0;
  std::cout << "Enter the element you want to find: ";
  std::cin >> x;

  auto result = BinarySearch(array, x);

  if (result.has_value()) {
    std::cout << "Found: " << x << " at index " << result.value() << '\n';
  } else {
    std::cout << x << " not found\n";
  }

  return 0;
}
