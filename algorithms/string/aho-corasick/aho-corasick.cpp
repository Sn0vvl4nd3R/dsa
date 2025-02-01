#include <iostream>
#include <vector>
#include <queue>
#include <string>

const int ALPH = 26;

struct AhoNode {
  std::vector<int> next, link_out;
  int fail;
  bool terminal;
  AhoNode(): next(ALPH, -1), link_out(ALPH, -1), fail(-1), terminal(false) {}
};

std::vector<AhoNode> AhoTrie;

void Init(void) {
  AhoTrie.clear();
  AhoTrie.push_back(AhoNode());
}

void AddString(const std::string& s) {
  int cur = 0;
  for (char c : s) {
    int cidx = c - 'a';
    if (AhoTrie[cur].next[cidx] == -1) {
      AhoTrie[cur].next[cidx] = AhoTrie.size();
      AhoTrie.push_back(AhoNode());
    }
    cur = AhoTrie[cur].next[cidx];
  }
  AhoTrie[cur].terminal = true;
}

void BuildAho(void) {
  std::queue<int> q;
  for (int c = 0; c < ALPH; c++) {
    int next = AhoTrie[0].next[c];
    if (next != -1) {
      AhoTrie[next].fail = 0;
      q.push(next);
    } else {
      AhoTrie[0].next[c] = 0;
    }
  }

  while (!q.empty()) {
    int u = q.front();
    q.pop();
    int f = AhoTrie[u].fail;
    AhoTrie[u].terminal = AhoTrie[u].terminal || AhoTrie[f].terminal;

    for (int c = 0; c < ALPH; c++) {
      int next = AhoTrie[u].next[c];
      if (next != -1) {
        AhoTrie[next].fail = AhoTrie[f].next[c];
        q.push(next);
      } else {
        AhoTrie[u].next[c] = AhoTrie[f].next[c];
      }
    }
  }
}

int main(void) {
  Init();
  AddString("he");
  AddString("she");
  AddString("his");
  AddString("hers");
  BuildAho();

  std::string text = "ahishers";
  int cur = 0;
  for (int i = 0; i < (int)text.size(); i++) {
    int c = text[i] - 'a';
    cur = AhoTrie[cur].next[c];
    if (AhoTrie[cur].terminal) {
      std::cout << "Found pattern at index: " << i << '\n';
    }
  }

  return 0;
}
