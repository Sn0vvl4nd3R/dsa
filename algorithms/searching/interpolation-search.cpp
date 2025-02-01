#include <iostream>
#include <vector>
#include <optional>
#include <algorithm>

template <typename T>
std::optional<size_t> InterpolationSearch(const std::vector<T>& array, const T& target){
  if (array.empty()) {
    return std::nullopt;
  }

  size_t left = 0;
  size_t right = array.size() - 1;

  while (left <= right && target >= array[left] && target <= array[right]) {
    if (left == right) {
      if (array[left] == target) {
        return left;
      }
      return std::nullopt;
    }

    size_t pos = left + (size_t)((double)(right - left) * (double)(target - array[left]) / (double)(array[right] - array[left]));

    if (array[pos] == target) {
      return pos;
    } else if (array[pos] < target) {
      left = pos + 1;
    } else {
      right = pos - 1;
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

  auto result = InterpolationSearch(array, x);

  if (result.has_value()) {
    std::cout << "Found " << x << " at index " << result.value() << '\n';
  } else {
    std::cout << x << " not found\n";
  }

  return 0;
}
