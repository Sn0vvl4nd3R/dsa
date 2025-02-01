#include <iostream>
#include <vector>
#include <algorithm>

static int GetDigit(int number, int exp) {
  return (number / exp) % 10;
}

void CountingSortForRadix(std::vector<int>& array, int exp) {
  std::vector<int> output(array.size());
  std::vector<int> count(10, 0);

  for (int num : array) {
    int digit = GetDigit(num, exp);
    count[digit]++;
  }

  for (size_t i = 1; i < count.size(); i++) {
    count[i] += count[i - 1];
  }

  for (int i = static_cast<int>(array.size()) - 1; i >= 0; i--) {
    int digit = GetDigit(array[i], exp);
    count[digit]--;
    output[count[digit]] = array[i];
  }

  array = output;
}

void RadixSort(std::vector<int>& array) {
  if (array.empty()) {
    return;
  }

  int max_val = *std::max_element(array.begin(), array.end());

  for (int exp = 1; max_val / exp > 0; exp *= 10) {
    CountingSortForRadix(array, exp);
  }
}

int main(void) {
  std::vector<int> array;
  int value = 0;

  std::cout << "Enter elements (enter 0 to finish):\n";
  while (std::cin >> value && value != 0) {
    array.push_back(value);
  }

  RadixSort(array);

  for (auto x : array) {
    std::cout << x << ' ';
  }
  std::cout << '\n';

  return 0;
}
