#include <iostream>
#include <vector>
#include <queue>

using Graph = std::vector<std::vector<int>>;

void Bfs(const Graph& g, int start) {
  std::vector<bool> visited(g.size(), false);
  std::queue<int> q;

  visited[start] = true;
  q.push(start);

  while (!q.empty()) {
    int v = q.front();
    q.pop();
    std:: cout << v << ' ';

    for (int neighbor : g[v]) {
      if (!visited[neighbor]) {
        visited[neighbor] = true;
        q.push(neighbor);
      }
    }
  }
}

int main(void) {
  Graph g = {
    {1, 2},
    {0, 3},
    {0, 1, 4},
    {1, 2},
    {0}
  };

  Bfs(g, 0);
  std::cout << '\n';

  return 0;
}
