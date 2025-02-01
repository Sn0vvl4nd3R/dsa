#include <iostream>
#include <vector>
#include <string>
#include <cmath>

static const int base = 257;
static const int mod = 1'000'000'007;

long long ModPow(long long a, long long p) {
  long long res = 1;
  while (p > 0) {
    if (p & 1) {
      res = (res * a) % mod;
    }
    a = (a * a) % mod;
    p >>= 1;
  }

  return res;
}

std::vector<int> RabinKarpSearch(const std::string& text, const std::string& pattern) {
  std::vector<int> occurrences;
  int n = text.size();
  int m = pattern.size();
  if (m == 0) {
    for (int i = 0; i < n; i++) {
      occurrences.push_back(i);
    }
    return occurrences;
  }
  if (m > n) {
    return occurrences;
  }

  long long base_pow = ModPow(base, m - 1);

  long long hash_p = 0;
  long long hash_t = 0;
  for (int i = 0; i < m; i++) {
    hash_p = (hash_p * base + (unsigned char)pattern[i]) % mod;
    hash_t = (hash_t * base + (unsigned char)text[i]) % mod;
  }

  for (int i = 0; i <= n - m; i++) {
    if (hash_p == hash_t) {
      bool match = true;
      for (int j = 0; j < m; j++) {
        if (text[i + j] != pattern[j]) {
          match = false;
          break;
        }
      }
      if (match) {
        occurrences.push_back(i);
      }
    }
    if (i < n - m) {
      long long left_val = (unsigned char)text[i];
      long long right_val = (unsigned char)text[i + m];
      hash_t = (hash_t - (left_val * base_pow) % mod + mod) % mod;
      hash_t = (hash_t * base + right_val) % mod;
    }
  }

  return occurrences;
}

int main(void) {
  std::string text;
  std::cout << "Enter your text:\n";
  std::cin >> text;

  std::string pattern;
  std::cout << "Enter the pattern to search: ";
  std::cin >> pattern;

  auto occ = RabinKarpSearch(text, pattern);
  for (auto pos : occ) {
    std::cout << "Found at index: " << pos << '\n';
  }

  return 0;
}
