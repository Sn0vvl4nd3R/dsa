#include <iostream>
#include <vector>
#include <limits>

int main(void) {
  const int INF = std::numeric_limits<int>::max();
  int n = 4;
  std::vector<std::vector<int>> dist = {
    {0, 5, INF, 10},
    {INF, 0, 3, INF},
    {INF, INF, 0, 1},
    {INF, INF, INF, 0}
  };

  for (int k = 0; k < n; k++) {
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++) {
        if (dist[i][k] < INF && dist[k][j] < INF) {
          dist[i][j] = std::min(dist[i][j], dist[i][k] + dist[k][j]);
        }
      }
    }
  }

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      if (dist[i][j] == INF) {
        std::cout << "INF ";
      } else {
        std::cout << dist[i][j] << ' ';
      }
    }
    std::cout << '\n';
  }

  return 0;
}
