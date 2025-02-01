#include <iostream>
#include <vector>
#include <algorithm>

std::vector<int> CountingSort(const std::vector<int>& array) {
  if (array.empty()) {
    return {};
  }

  int max_val = *std::max_element(array.begin(), array.end());

  std::vector<int> count(max_val + 1, 0);

  for (int num : array) {
    count[num]++;
  }

  for (size_t i = 1; i < count.size(); i++) {
    count[i] += count[i - 1];
  }

  std::vector<int> output(array.size());
  for (int i = static_cast<int>(array.size()) - 1; i >= 0; i--) {
    int num = array[i];
    count[num]--;
    int pos = count[num];
    output[pos] = num;
  }

  return output;
}

int main(void) {
  std::vector<int> array;
  int value = 0;

  std::cout << "Enter elements (enter 0 to finish):\n";
  while (std::cin >> value && value != 0) {
    array.push_back(value);
  }

  std::vector<int> sorted = CountingSort(array);

  for (auto x : sorted) {
    std::cout << x << ' ';
  }
  std::cout << '\n';

  return 0;
}
