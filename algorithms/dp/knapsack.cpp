#include <iostream>
#include <vector>

int Knapsack(int capacity, const std::vector<int>& weights, const std::vector<int>& values) {
  int n = weights.size();
  std::vector<std::vector<int>> dp(n + 1, std::vector<int>(capacity + 1, 0));
  for (int i = 1; i <= n; i++) {
    for (int w = 0; w <= capacity; w++) {
      if (weights[i - 1] <= w) {
        dp[i][w] = std::max(dp[i - 1][w], dp[i - 1][w - weights[i - 1]] + values[i - 1]);
      } else {
        dp[i][w] = dp[i - 1][w];
      }
    }
  }

  return dp[n][capacity];
}

int main(void) {
  int n = 0;
  int capacity = 0;
  std::cout << "Enter the amount of items and the capacity of the knapsack: ";
  std::cin >> n >> capacity;

  std::vector<int> weights(n), values(n);
  std::cout << "Enter the weight and the value of each item:\n";
  for (int i = 0; i < n; i++) {
    std::cin >> weights[i] >> values[i];
  }

  int max_val = Knapsack(capacity, weights, values);
  std::cout << "Maximum value: " << max_val;

  return 0;
}
