#include <iostream>
#include <vector>
#include <stack>

using Graph = std::vector<std::vector<int>>;

void TopologicalSortDFS(const Graph& g, int v, std::vector<bool>& visited, std::stack<int>& st) {
  visited[v] = true;
  for (int neighbor : g[v]) {
    if (!visited[neighbor]) {
      TopologicalSortDFS(g, neighbor, visited, st);
    }
  }

  st.push(v);
}

std::vector<int> TopologicalSort(const Graph& g) {
  std::vector<bool> visited(g.size(), false);
  std::stack<int> st;

  for (size_t i = 0; i < g.size(); i++) {
    if (!visited[i]) {
      TopologicalSortDFS(g, i, visited, st);
    }
  }

  std::vector<int> order;
  order.reserve(g.size());
  while (!st.empty()) {
    order.push_back(st.top());
    st.pop();
  }
  return order;
}

int main(void) {
  Graph g = {
    {1, 2},
    {3},
    {3, 4},
    {},
    {}
  };

  auto order = TopologicalSort(g);
  for (int v : order) {
    std::cout << v << ' ';
  }
  std::cout << '\n';

  return 0;
}
