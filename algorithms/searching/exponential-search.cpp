#include <iostream>
#include <vector>
#include <optional>
#include <algorithm>

template <typename T>
std::optional<size_t> BinarySearchRange(const std::vector<T>& array, size_t left, size_t right, const T& target) {
  while (left <= right && right < array.size()) {
    size_t mid = left + (right - left) / 2;
    if (array[mid] == target) {
      return mid;
    } else if (array[mid] < target) {
      left = mid + 1;
    } else {
      if (mid == 0) {
        break;
      }
      right = mid - 1;
    }
  }
  return std::nullopt;
}

template <typename T>
std::optional<size_t> ExponentialSearch(const std::vector<T>& array, const T& target) {
  if (array.empty()) {
    return std::nullopt;
  }

  if (array[0] == target) {
    return 0;
  }

  size_t bound = 1;
  while (bound < array.size() && array[bound] < target) {
    bound *= 2;
  }

  size_t left = bound / 2;
  size_t right = std::min(bound, array.size() - 1);
  return BinarySearchRange(array, left, right, target);
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

  auto result = ExponentialSearch(array, x);

  if (result.has_value()) {
    std::cout << "Found " << x << " at index " << result.value() << '\n';
  } else {
    std::cout << x << " not found\n";
  }

  return 0;
}
