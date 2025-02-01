#include <iostream>
#include <vector>
#include <queue>
#include <limits>

using Graph = std::vector<std::vector<int>>;

std::vector<int> ShortestPathUnweighter(const Graph& g, int start) {
  std::vector<int> dist(g.size(), std::numeric_limits<int>::max());
  std::queue<int> q;
  dist[start] = 0;
  q.push(start);

  while (!q.empty()) {
    int v = q.front();
    q.pop();

    for (int neighbor : g[v]) {
      if (dist[neighbor] == std::numeric_limits<int>::max()) {
        dist[neighbor] = dist[v] + 1;
        q.push(neighbor);
      }
    }
  }
  return dist;
}
