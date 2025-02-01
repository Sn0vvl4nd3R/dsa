#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

std::vector<int> BuildSuffixArray(const std::string& s) {
  int n = s.size();
  std::vector<int> sa(n);
  std::vector<int> ranks(n);
  std::vector<int> temp(n);
  for (int i = 0; i < n; i++) {
    sa[i] = i;
    ranks[i] = s[i];
  }

  for (int k = 1; k < n; k *= 2) {
    auto cmp = [&](int a, int b) {
      if (ranks[a] != ranks[b]) {
        return ranks[a] < ranks[b];
      }
      int ra = (a + k < n) ? ranks[a + k] : -1;
      int rb = (b + k < n) ? ranks[b + k] : -1;
      return ra < rb;
    };
    std::sort(sa.begin(), sa.end(), cmp);

    temp[sa[0]] = 0;
    for (int i = 1; i < n; i++) {
      temp[sa[i]] = temp[sa[i - 1]] + (cmp(sa[i - 1], sa[i]) ? 1 : 0);
    }
    ranks = temp;
    if (ranks[sa[n - 1]] == n - 1) {
      break;
    }
  }

  return sa;
}

int main(void) {
  std::string text;
  std::cout << "Enter your text:\n";
  std::cin >> text;

  auto sa = BuildSuffixArray(text);
  for (auto idx : sa) {
    std::cout << idx << ' ' << text.substr(idx) << '\n';
  }

  return 0;
}
