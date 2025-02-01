#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

static const int ALPHABET_SIZE = 256;

void BuildBadCharTable(const std::string& pattern, std::vector<int>& bad_char) {
  std::fill(bad_char.begin(), bad_char.end(), -1);
  for (int i = 0; i < (int)pattern.size(); i++) {
    bad_char[(unsigned char)pattern[i]] = i;
  }
}

std::vector<int> BoyerMooreSearch(const std::string& text, const std::string& pattern) {
  std::vector<int> occurrences;
  int n = text.size();
  int m = text.size();
  if (m == 0) {
    for (int i = 0; i < n; i++) {
      occurrences.push_back(i);
    }
    return occurrences;
  }

  std::vector<int> bad_char(ALPHABET_SIZE);
  BuildBadCharTable(pattern, bad_char);

  int s = 0;
  while (s <= n - m) {
    int j = m - 1;
    while (j >= 0 && pattern[j] == text[s + j]) {
      j--;
    }
    if (j < 0) {
      occurrences.push_back(s);
      s += (s + m < n) ? m - bad_char[(unsigned char)text[s + m]] : 1;
    } else {
      int shift = j - bad_char[(unsigned char)text[s + j]];
      s += std::max(1, shift);
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

  auto occ = BoyerMooreSearch(text, pattern);
  for (auto pos : occ) {
    std::cout << "Found at index: " << pos << '\n';
  }

  return 0;
}
