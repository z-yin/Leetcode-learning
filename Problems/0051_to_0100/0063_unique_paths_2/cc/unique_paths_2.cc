#include <stdint.h>
#include <vector>
using namespace std;

// 4 ms, 9.7 MB. DP
class Solution {
 public:
  int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
    int m = obstacleGrid.size();
    int n = obstacleGrid[0].size();
    memo_ = vector<vector<int64_t>>(n, vector<int64_t>(m, -1));
    memo_[0][0] = 1;
    return GetUniquePathsWithObstacles(obstacleGrid, m - 1, n - 1);
  };

 private:
  vector<vector<int64_t>> memo_;

  int64_t GetUniquePathsWithObstacles(const vector<vector<int>>& obstacleGrid,
                                      const int& m, const int& n) {
    if (obstacleGrid[m][n] == 1) {
      return 0;
    }
    if (memo_[n][m] != -1) {
      return memo_[n][m];
    }
    if (m == 0) {
      memo_[n][m] = GetUniquePathsWithObstacles(obstacleGrid, m, n - 1);
    } else if (n == 0) {
      memo_[n][m] = GetUniquePathsWithObstacles(obstacleGrid, m - 1, n);
    } else {
      memo_[n][m] = GetUniquePathsWithObstacles(obstacleGrid, m, n - 1) +
                    GetUniquePathsWithObstacles(obstacleGrid, m - 1, n);
    }
    return memo_[n][m];
  }
};