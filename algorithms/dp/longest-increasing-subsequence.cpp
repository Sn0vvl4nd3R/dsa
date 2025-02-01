#include <iostream>
#include <vector>
#include <algorithm>

int LongestIncreasingSubsequence(const std::vector<int>& array) {
  if (array.empty()) {
    return 0;
  }

  int n = array.size();
  std::vector<int> dp(n, 1);
  for (int i = 0; i <= n; i++) {
    for (int j = 0; j <= i; j++) {
      if (array[j] < array[i] && dp[j] + 1 > dp[i]) {
        dp[i] = dp[j] + 1;
      }
    }
  }

  return *std::max_element(dp.begin(), dp.end());
}

int main(void) {
  std::vector<int> sequence;
  int value = 0;

  std::cout << "Enter the elements of the sequence (enter 0 to stop):\n";
  while (std::cin >> value && value != 0) {
    sequence.push_back(value);
  }

  int lis_length = LongestIncreasingSubsequence(sequence);
  std::cout << "The length of the longest increasing subsequence: " << lis_length << '\n';

  return 0;
}
