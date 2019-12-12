#include <vector>
using namespace std;

// 8 ms	10.5 MB. DFS.
class Solution {
 public:
  int numIslands(vector<vector<char>>& grid) {
    if (grid.empty()) return 0;

    int res = 0;
    for (int i = 0; i < grid.size(); ++i) {
      for (int j = 0; j < grid[0].size(); ++j) {
        if (grid[i][j] == '1') {
          ++res;
          dfs(grid, i, j);
        }
      }
    }
    return res;
  }

  void dfs(vector<vector<char>>& g, int i, int j) {
    if (i < 0 || i >= g.size() || j < 0 || j >= g[0].size()) return;
    if (g[i][j] != '1') return;
    g[i][j] = '#';
    dfs(g, i - 1, j);  // up
    dfs(g, i + 1, j);  // down
    dfs(g, i, j - 1);  // left
    dfs(g, i, j + 1);  // right
  }
};