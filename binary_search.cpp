#include <iostream>
#include <vector>

int BinarySearch(std::vector<int>& arr, int target) {
  int low = 0;
  int high = arr.size() - 1;
  int ans = -1;

  while (low <= high) {
    int middle = (high + low) / 2;
    if (arr[middle] == target) {
      ans = middle;
      break;
    } else if (arr[middle] < target) {
      low = middle + 1;
    } else {
      high = middle - 1;
    }
  }

  return ans;
}

int main(void) {
  std::vector<int> arr;
  int n = 0;

  std::cin >> n;
  
  while (n--) {
    int i = 0;
    std::cin >> i;
    arr.push_back(i);
  }

  int target = 0;
  std::cin >> target;

  int found = BinarySearch(arr, target);

  if (found == -1) {
    std::cout << "Not found\n";
  } else {
    std::cout << target << " found at " << found << '\n';
  }

  return 0;
}
