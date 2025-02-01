#include <iostream>
#include <vector>
#include <limits>

struct Edge {
  int u, v;
  int w;
};

std::vector<int> BellmanFord(int n, const std::vector<Edge>& edges, int start) {
  const int INF = std::numeric_limits<int>::max();
  std::vector<int> dist(n, INF);
  dist[start] = 0;

  for (int i = 0; i < n - 1; i++) {
    bool updated = false;
    for (auto &e : edges) {
      if (dist[e.u] != INF && dist[e.u] + e.w < dist[e.v]) {
        dist[e.v] = dist[e.u] + e.w;
        updated = true;
      }
    }
    if (!updated) {
      break;
    }
  }

  return dist;
}

int main(void) {
  int n = 5;
  std::vector<Edge> edges = {
    {0, 1, 2},
    {0, 2, 4},
    {1, 2, 1},
    {1, 3, 7},
    {2, 4, 3},
    {3, 4, 2}
  };

  auto dist = BellmanFord(n, edges, 0);
  for (int d : dist) {
    std::cout << d << ' ';
  }
  std::cout << '\n';

  return 0;
}
