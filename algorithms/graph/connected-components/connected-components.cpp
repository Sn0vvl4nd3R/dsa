#include <iostream>
#include <vector>

using Graph = std::vector<std::vector<int>>;

void DfsUtil(const Graph& g, int v, std::vector<bool>& visited) {
  visited[v] = true;
  for (int neighbor : g[v]) {
     if (!visited[neighbor]) {
        DfsUtil(g, neighbor, visited);
     }
  }
}

int main(void) {
  Graph g = {
    {1},
    {0},
    {3},
    {2},
    {5},
    {4}
  };

  std::vector<bool> visited(g.size(), false);
  int components = 0;

  for (size_t i = 0; i < g.size(); i++) {
    if (!visited[i]) {
      components++;
      DfsUtil(g, i, visited);
    }
  }

  std::cout << "Components: " << components << '\n';
  return 0;
}
