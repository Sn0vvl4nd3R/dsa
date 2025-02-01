#include <iostream>
#include <vector>

template <typename T>
void InsertionSort(std::vector<T>& array) {
  for (size_t i = 1; i < array.size(); i++) {
    T key = array[i];
    int j = static_cast<int>(i) - 1;
    while (j >= 0 && array[j] > key) {
      array[j + 1] = array[j];
      j--;
    }
    array[j + 1] = key;
  }
}

std::vector<double> BucketSort(const std::vector<double>& array, size_t bucket_count = 10) {
  if (array.empty()) {
    return {};
  }

  std::vector<std::vector<double>> buckets(bucket_count);

  double min_val = array[0], max_val = array[0];
  for (double x : array) {
    if (x < min_val) {
      min_val = x;
    }
    if (x > max_val) {
      max_val = x;
    }
  }
  double range = max_val - min_val;

  for (double x : array) {
    size_t bi = static_cast<size_t>(((x - min_val) / range) * (bucket_count - 1));
    buckets[bi].push_back(x);
  }

  for (auto &b : buckets) {
    InsertionSort(b);
  }

  std::vector<double> output;
  output.reserve(array.size());
  for (auto &b : buckets) {
    for (auto x : b) {
      output.push_back(x);
    }
  }

  return output;
}

int main(void) {
  std::vector<double> array;
  double value = 0.0;

  std::cout << "Enter elements (enter 0 to finish):\n";
  while (std::cin >> value && value != 0) {
    array.push_back(value);
  }

  std::vector<double> sorted = BucketSort(array);

  for (double x : sorted) {
    std::cout << x << ' ';
  }
  std::cout << '\n';

  return 0;
}
