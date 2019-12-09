#include <vector>
using namespace std;

// 28 ms	14.1 MB. DFS.
class Solution {
 public:
  int r, c;

  void solve(vector<vector<char>>& b) {
    if (b.empty()) return;
    r = b.size();
    c = b[0].size();

    for (int i = 0; i < r; ++i) {
      if (b[i][0] == 'O') dfs(b, i, 0);
      if (b[i][c - 1] == 'O') dfs(b, i, c - 1);
    }
    for (int j = 0; j < c; ++j) {
      if (b[0][j] == 'O') dfs(b, 0, j);
      if (b[r - 1][j] == 'O') dfs(b, r - 1, j);
    }

    for (auto& v : b) {
      for (auto& c : v) {
        if (c == '#')
          c = 'O';
        else if (c == 'O')
          c = 'X';
      }
    }
  }

  void dfs(vector<vector<char>>& b, int i, int j) {
    if (i < 0 || i >= r || j < 0 || j >= c || b[i][j] != 'O') return;
    b[i][j] = '#';
    dfs(b, i - 1, j);
    dfs(b, i + 1, j);
    dfs(b, i, j - 1);
    dfs(b, i, j + 1);
  }
};