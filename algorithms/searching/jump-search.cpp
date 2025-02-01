#include <iostream>
#include <vector>
#include <cmath>
#include <optional>

template <typename T>
std::optional<size_t> JumpSearch(const std::vector<T>& array, const T& target) {
  size_t n = array.size();
  if (n == 0) {
    return std::nullopt;
  }

  size_t step = static_cast<size_t>(std::sqrt(n));
  size_t prev = 0;

  while (array[std::min(step, n) - 1] < target) {
    prev = step;
    step += static_cast<size_t>(std::sqrt(n));
    if (prev >= n) {
      return std::nullopt;
    }
  }

  for (size_t i = prev; i < std::min(step, n); i++) {
    if (array[i] == target) {
      return i;
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

  int x = 0;
  std::cout << "Enter the element you want to find: ";
  std::cin >> x;

  auto result = JumpSearch(array, x);

  if (result.has_value()) {
    std::cout << "Found " << x << " at index " << result.value() << '\n';
  } else {
    std::cout << x << " not found\n";
  }

  return 0;
}
