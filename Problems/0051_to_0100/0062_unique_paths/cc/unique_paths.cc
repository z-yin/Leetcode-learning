#include <vector>
using namespace std;

// 4 ms, 8.8 MB. DP
class Solution {
 public:
  int uniquePaths(int m, int n) {
    memo_ = vector<vector<int>>(n, vector<int>(m, -1));
    for (int i = 1; i < n; ++i) {
      memo_[i][0] = 1;
    }
    for (int i = 0; i < m; ++i) {
      memo_[0][i] = 1;
    }
    return GetUniquePaths(m - 1, n - 1);
  }

 private:
  vector<vector<int>> memo_;

  int GetUniquePaths(const int& m, const int& n) {
    if (memo_[n][m] != -1) {
      return memo_[n][m];
    }
    memo_[n][m] = GetUniquePaths(m - 1, n) + GetUniquePaths(m, n - 1);
    return memo_[n][m];
  }
};