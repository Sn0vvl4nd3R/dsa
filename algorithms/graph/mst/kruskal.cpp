#include <iostream>
#include <vector>
#include <algorithm>

struct Edge {
  int u, v;
  int w;
};

struct DSU {
  std::vector<int> parent, rank;

  DSU(int n) : parent(n), rank(n, 0) {
    for (int i = 0; i < n; i++) {
      parent[i] = i;
    }
  }

  int find(int x) {
    if (parent[x] != x) {
      parent[x] = find(parent[x]);
    }
    return parent[x];
  }

  void unite(int a, int b) {
    a = find(a);
    b = find(b);
    if (a != b) {
      if (rank[a] < rank[b]) {
        std::swap(a, b);
      }
      parent[b] = a;
      if (rank[a] == rank[b]) {
        rank[a]++;
      }
    }
  }
};

int main(void) {
  int n = 4;
  std::vector<Edge> edges = {
    {0, 1, 10},
    {0, 2, 6},
    {0, 3, 5},
    {1, 3, 15},
    {2, 3, 4}
  };

  std::sort(edges.begin(), edges.end(), [](auto &a, auto &b) {
    return a.w < b.w;
  });

  DSU dsu(n);
  std::vector<Edge> mst;
  for (auto &e : edges) {
    if (dsu.find(e.u) != dsu.find(e.v)) {
      dsu.unite(e.u, e.v);
      mst.push_back(e);
    }
  }

  std::cout << "MST edges:\n";
  for (auto &e : mst) {
    std::cout << e.u << " - " << e.v << " (weight " << e.w << ")\n";
  }

  return 0;
}
