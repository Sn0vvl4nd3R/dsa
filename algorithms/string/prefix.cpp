#include <bits/stdc++.h>

using namespace std;

vector<int> Prefix(const string& s) {
  vector<int> pi(s.size(), 0);
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
  string s;
  cout << "Enter your string:\n";
  cin >> s;

  vector<int> pref = Prefix(s);
  for (int& x : pref) {
    cout << x << ' ';
  }

  return 0;
}
