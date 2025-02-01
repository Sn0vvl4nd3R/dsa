#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <limits>

int EdmondsKarp(std::vector<std::vector<int>>& capacity, int source, int sink) {
  int n = capacity.size();
  int max_flow = 0;

  while (true) {
    std::vector<int> parent(n, -1);
    parent[source] = source;
    std::queue<int> q;
    q.push(source);

    while (!q.empty() && parent[sink] == -1) {
      int u = q.front();
      q.pop();
      for (int v = 0; v < n; v++) {
        if (parent[v] == -1 && capacity[u][v] > 0) {
          parent[v] = u;
          q.push(v);
          if (v == sink) {
            break;
          }
        }
      }
    }
    if (parent[sink] == -1) {
      break;
    }

    int flow = std::numeric_limits<int>::max();
    int v = sink;
    while (v != source) {
      int u = parent[v];
      flow = std::min(flow, capacity[u][v]);
      v = u;
    }

    v = sink;
    while (v != source) {
      int u = parent[v];
      capacity[u][v] -= flow;
      capacity[v][u] += flow;
      v = u;
    }
    max_flow += flow;
  }
  return max_flow;
}

int main(void) {
  std::vector<std::vector<int>> capacity = {
    {0, 3, 2, 0},
    {0, 0, 0, 2},
    {0, 1, 0, 2},
    {0, 0, 0, 0}
  };
  std::cout << EdmondsKarp(capacity, 0, 3) << '\n';
  return 0;
}
