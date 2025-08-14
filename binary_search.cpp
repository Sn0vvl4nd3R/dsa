#include <iostream>
#include <vector>

bool BinarySearch(std::vector<int>& v, int target) {
  int low = 0;
  int high = v.size() - 1;

  while (low <= high) {
    int mid = ((high - low) / 2) + low;

    if (v[mid] == target) {
      return true;
    }

    if (v[mid] > target) {
      high = mid - 1;
    } else {
      low = mid + 1;
    }
  }

  return false;
}

int main(void) {
  std::vector<int> v = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11};
  int target = 3;

  if (BinarySearch(v, target)) {
    std::cout << target << " found.";
  } else {
    std::cout << target << " not found.";
  }

  return 0;
}
