#include <iostream>
#include <vector>
#include <string>

std::vector<int> ComputePrefixFunction(const std::string& pattern) {
  std::vector<int> pi(pattern.size(), 0);
  int j = 0;

  for (int i = 1; i < (int)pattern.size(); i++) {
    while (j > 0 && pattern[i] != pattern[j]) {
      j = pi[j - 1];
    }
    if (pattern[i] == pattern[j]) {
      j++;
    }
    pi[i] = j;
  }

  return pi;
}

std::vector<int> KmpSearch(const std::string& text, const std::string& pattern) {
  std::vector<int> occurrences;
  if (pattern.empty()) {
    for (int i = 0; i < (int)text.size(); i++) {
      occurrences.push_back(i);
    }

    return occurrences;
  }

  auto pi = ComputePrefixFunction(pattern);
  int j = 0;
  for (int i = 0; i < (int)text.size(); i++) {
    while (j > 0 && text[i] != pattern[j]) {
      j = pi[j - 1];
    }
    if (text[i] == pattern[j]) {
      j++;
    }
    if (j == (int)pattern.size()) {
      occurrences.push_back(i - j + 1);
      j = pi[j - 1];
    }
  }

  return occurrences;
}

int main(void) {
  std::string text;
  std::cout << "Enter your test:\n";
  std::cin >> text;

  std::string pattern;
  std::cout << "Enter the pattern to search: ";
  std::cin >> pattern;

  auto occ = KmpSearch(text, pattern);
  for (auto pos : occ) {
    std::cout << "Found at index: " << pos << '\n';
  }

  return 0;
}
