#include <iostream>
#include <vector>
#include <string>

std::vector<int> ZFunction(const std::string& s) {
  int n = s.size();
  std::vector<int> z(n, 0);
  int l = 0;
  int r = 0;

  for (int i = 1; i < n; i++) {
    if (i <= r) {
      z[i] = std::min(r - i + 1, z[i - l]);
    }
    while (i + z[i] < n && s[z[i]] == s[i + z[i]]) {
      z[i]++;
    }
    if (i + z[i] - 1 > r) {
      l = i;
      r = i + z[i] - 1;
    }
  }

  return z;
}

int main(void) {
  std::string s;
  std::cout << "Enter your text:\n";
  std::cin >> s;

  auto z = ZFunction(s);
  for (int i = 0; i < (int)z.size(); i++) {
    std::cout << "z[" << i << "] = " << z[i] << '\n';
  }

  return 0;
}
