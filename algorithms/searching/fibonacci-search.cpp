#include <iostream>
#include <vector>
#include <optional>
#include <algorithm>

std::vector<size_t> GenerateFibonacciSequence(size_t n) {
  std::vector<size_t> fib = {0, 1};
  while (fib.back() < n) {
    fib.push_back(fib[fib.size() - 1] + fib[fib.size() - 2]);
  }
  return fib;
}

template <typename T>
std::optional<size_t> FibonacciSearch(const std::vector<T>& array, const T& target) {
  size_t n = array.size();
  if (n == 0) {
    return std::nullopt;
  }

  auto fib = GenerateFibonacciSequence(n);

  int fib_index = fib.size() - 1;

  size_t offset = 0;

  while (fib_index > 1) {
    size_t i = std::min(offset + fib[fib_index - 2], n - 1);

    if (array[i] < target) {
      fib_index--;
      offset = i;
    } else if (array[i] > target) {
      fib_index -= 2;
    } else {
      return i;
    }
  }

  if (fib_index == 1 && offset < n && array[offset] == target) {
    return offset;
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
  auto result = FibonacciSearch(array, x);

  if (result.has_value()) {
    std::cout << "Found " << x << " at index " << result.value() << '\n';
  } else {
    std::cout << x << " not found\n" << std::endl;
  }

  return 0;
}
