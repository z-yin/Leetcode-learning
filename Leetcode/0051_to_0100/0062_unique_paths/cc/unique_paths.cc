#include <vector>
using namespace std;

// 0 ms	8.6 MB. DP
class Solution {
 public:
  int uniquePaths(int m, int n) {
    vector<vector<int>> mat(2, vector<int>(n, 0));
    for (int i = 1; i < 2; ++i) mat[i][0] = 1;
    for (int i = 0; i < n; ++i) mat[0][i] = 1;
    for (int i = 1; i < m; ++i) {
      for (int j = 1; j < n; ++j) {
        mat[i % 2][j] = mat[(i - 1) % 2][j] + mat[i % 2][j - 1];
      }
    }
    return mat[(m - 1) % 2][n - 1];
  }
};