#include <iostream>
#include <vector>

long long Fibonacci(int n) {
  if (n < 0) {
    return 0;
  }

  std::vector<long long> dp(n + 1, 0);
  dp[0] = 0;
  if (n >= 1) {
    dp[1] = 1;
  }
  for (int i = 2; i <= n; i++) {
    dp[i] = dp[i - 1] + dp[i - 2];
  }

  return dp[n];
}

int main(void) {
  int n = 0;
  std::cout << "Enter the number of the Fibonacci number: ";
  std::cin >> n;

  long long result = Fibonacci(n);
  std::cout << result << '\n';

  return 0;
}
