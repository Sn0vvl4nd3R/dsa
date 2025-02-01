#include <iostream>
#include <vector>

using Graph = std::vector<std::vector<int>>;

void DfsUtil(const Graph& g, int v, std::vector<bool>& visited) {
  visited[v] = true;
  std::cout << v << ' ';

  for (int neighbor : g[v]) {
    if (!visited[neighbor]) {
      DfsUtil(g, neighbor, visited);
    }
  }
}

void Dfs(const Graph& g, int start) {
  std::vector<bool> visited(g.size(), false);
  DfsUtil(g, start, visited);
}

int main(void) {
  Graph g = {
    {1, 2},
    {0, 3},
    {0, 3, 4},
    {1, 2},
    {0}
  };

  Dfs(g, 0);
  std::cout << '\n';

  return 0;
}
