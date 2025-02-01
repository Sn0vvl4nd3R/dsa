#include <iostream>
#include <vector>
#include <queue>
#include <limits>

struct Edge {
  int to;
  int w;
};

using Graph = std::vector<std::vector<Edge>>;

std::vector<int> Dijkstra(const Graph& g, int start) {
  const int INF = std::numeric_limits<int>::max();
  std::vector<int> dist(g.size(), INF);
  dist[start] = 0;

  using pii = std::pair<int, int>;
  std::priority_queue<pii, std::vector<pii>, std::greater<>> pq;
  pq.push({0, start});

  while (!pq.empty()) {
    auto [cdist, u] = pq.top();
    pq.pop();
    if (cdist > dist[u]) {
      continue;
    }

    for (auto &edge : g[u]) {
      int v = edge.to;
      int w = edge.w;
      if (dist[u] + w < dist[v]) {
        dist[v] = dist[u] + w;
        pq.push({dist[v], v});
      }
    }
  }

  return dist;
}

int main(void) {
  Graph g = {
    {{1, 2}, {2, 4}},
    {{2, 1}, {3, 7}},
    {{4, 3}},
    {{4, 2}},
    {}
  };

  std::vector<int> dist = Dijkstra(g, 0);
  for (int d : dist) {
    std::cout << d << ' ';
  }
  std::cout << '\n';

  return 0;
}
