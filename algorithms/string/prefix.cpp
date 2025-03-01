#include <iostream>
#include <vector>
#include <string>

std::vector<int> Prefix(const std::string& s) {
  std::vector<int> pi(s.size(), 0);
  for (int i = 0; i < (int)pi.size(); i++) {
    for (int j = 0; j < i; j++) {
      if (s.substr(0, j + 1) == s.substr(i - j, j + 1)) {
        pi[i] = j + 1;
      }
    }
  }
  return pi;
}

int main(void) {
  std::string s;
  std::cout << "Enter your string:\n";
  std::cin >> s;

  std::vector<int> pref = Prefix(s);
  for (int& x : pref) {
    std::cout << x << ' ';
  }

  return 0;
}
