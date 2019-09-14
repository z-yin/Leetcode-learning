#include <algorithm>
#include <vector>
using namespace std;

// 12 ms, 11.1 MB. DP
class Solution {
 public:
  int minPathSum(vector<vector<int>>& grid) {
    int m = grid.size();
    int n = grid[0].size();
    memo_ = vector<vector<int>>(m, vector<int>(n, -1));
    memo_[0][0] = grid[0][0];
    for (int i = 1; i < m; ++i) {
      memo_[i][0] = grid[i][0] + memo_[i - 1][0];
    }
    for (int i = 1; i < n; ++i) {
      memo_[0][i] = grid[0][i] + memo_[0][i - 1];
    }
    return GetMinPathSum(grid, m - 1, n - 1);
  }

 private:
  vector<vector<int>> memo_;

  int GetMinPathSum(const vector<vector<int>>& grid, const int& m,
                    const int& n) {
    if (memo_[m][n] != -1) {
      return memo_[m][n];
    }
    memo_[m][n] = grid[m][n] + min(GetMinPathSum(grid, m - 1, n),
                                   GetMinPathSum(grid, m, n - 1));
    return memo_[m][n];
  }
};