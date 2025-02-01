#include <iostream>
#include <vector>
#include <queue>
#include <limits>

struct Edge {
  int to;
  int w;
};

using Graph = std::vector<std::vector<Edge>>;

int main(void) {
  Graph g = {
    {{1, 10}, {2, 6}, {3, 5}},
    {{0, 10}, {3, 15}},
    {{0, 6}, {3, 4}},
    {{0, 5}, {1, 15}, {2, 4}}
  };
  int n = (int)g.size();

  std::vector<bool> inMST(n, false);
  std::vector<int> dist(n, std::numeric_limits<int>::max());
  std::vector<int> parent(n, -1);

  dist[0] = 0;

  using pii = std::pair<int, int>;
  std::priority_queue<pii, std::vector<pii>, std::greater<>> pq;
  pq.push({0, 0});

  while (!pq.empty()) {
    auto [cost, u] = pq.top();
    pq.pop();
    if (inMST[u]) {
      continue;
    }
    inMST[u] = true;

    for (auto &edge : g[u]) {
      int v = edge.to;
      int w = edge.w;
      if (!inMST[v] && w < dist[v]) {
        dist[v] = w;
        parent[v] = u;
        pq.push({w, v});
      }
    }
  }

  for (int i = 1; i < n; i++) {
    std::cout << parent[i] << " - " << i << " (weight " << dist[i] << ")\n";
  }

  return 0;
}
