#include <iostream>
#include <vector>
#include <optional>

template <typename T>
std::optional<size_t> LinearSearch(const std::vector<T>& array, const T& target) {
  for (size_t i = 0; i < array.size(); i++) {
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

  auto result = LinearSearch(array, x);

  if (result.has_value()) {
    std::cout << "Found: " << x << " at index " << result.value() << '\n';
  } else {
    std::cout << x << " not found\n";
  }

  return 0;
}
