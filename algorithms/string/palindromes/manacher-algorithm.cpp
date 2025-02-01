#include <iostream>
#include <string>
#include <vector>

std::vector<int> Manacher(const std::string& s) {
  std::string t;
  t.push_back('#');
  for (char c : s) {
    t.push_back(c);
    t.push_back('#');
  }
  int n = t.size();
  std::vector<int> p(n, 0);
  int center = 0;
  int right = 0;

  for (int i = 0; i < n; i++) {
    int mirror = 2 * center - i;
    if (i < right) {
      p[i] = std::min(right - i, p[mirror]);
    }

    while (i - p[i] - 1 >= 0 && i + p[i] + 1 < n && t[i - p[i] - 1] == t[i + p[i] + 1]) {
      p[i]++;
    }

    if (i + p[i] > right) {
      center = i;
      right = i + p[i];
    }
  }

  return p;
}

int main(void) {
  std::string text;
  std::cout << "Enter your test:\n";
  std::cin >> text;
  auto d = Manacher(text);

  for (int i = 0; i < (int)d.size(); i++) {
    std::cout << i << ':' << d[i] << ' ';
  }
  std::cout << '\n';

  return 0;
}
