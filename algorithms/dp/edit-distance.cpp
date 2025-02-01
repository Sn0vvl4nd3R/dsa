#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

int EditDistance(const std::string& s1, const std::string& s2) {
  int m = s1.size();
  int n = s2.size();

  std::vector<std::vector<int>> dp(m + 1, std::vector<int>(n + 1, 0));

  for (int i = 0; i <= m; i++) {
    dp[i][0] = i;
  }
  for (int j = 0; j <= n; j++) {
    dp[0][j] = j;
  }

  for (int i = 1; i <= m; i++) {
    for (int j = 1; j <= n; j++) {
      if (s1[i - 1] == s2[j - 1]) {
        dp[i][j] = dp[i - 1][j - 1];
      } else {
        dp[i][j] = std::min({ dp[i - 1][j], dp[i][j - 1], dp[i - 1][j - 1] }) + 1;
      }
    }
  }

  return dp[m][n];
}

int main(void) {
  std::string s1, s2;
  std::cout << "Enter your first line: ";
  std::getline(std::cin, s1);

  std::cout << "Enter your second line: ";
  std::getline(std::cin, s2);

  int distance = EditDistance(s1, s2);
  std::cout << "Edit Distance: " << distance << '\n';

  return 0;
}
