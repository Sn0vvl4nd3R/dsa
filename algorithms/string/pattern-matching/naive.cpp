#include <iostream>
#include <vector>
#include <string>

std::vector<int> NaiveSearch(const std::string& text, const std::string& pattern) {
  std::vector<int> occurrences;
  if (pattern.empty()) {
    for (int i = 0; i < (int)text.size(); i++) {
      occurrences.push_back(i);
    }
    return occurrences;
  }

  for (int i = 0; i + (int)pattern.size() <= (int)text.size(); i++) {
    bool match = true;
    for (int j = 0; j < (int)pattern.size(); j++) {
      if (text[i + j] != pattern[j]) {
        match = false;
        break;
      }
    }

    if (match) {
      occurrences.push_back(i);
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

  auto occ = NaiveSearch(text, pattern);
  for (auto pos : occ) {
    std::cout << "Found at index: " << pos << '\n';
  }

  return 0;
}
