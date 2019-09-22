#include <string>
#include <vector>
using namespace std;

// 4 ms, 10 MB. Backtracking.
class Solution {
 public:
  vector<vector<string>> solveNQueens(int n) {
    queen_col_ = vector<int>(n, -1);
    vector<string> solution(n, string(n, '.'));
    solve(n, 0, solution);
    return ret_;
  }

 private:
  vector<vector<string>> ret_;
  vector<int> queen_col_;

  // need to check for all previous queens rather than only the previous one
  bool isSafe(int row, int col) {
    for (int i = 0; i < row; ++i) {
      if (queen_col_[i] == col || abs(row - i) == abs(col - queen_col_[i])) {
        return false;
      }
    }
    return true;
  }

  void solve(int n, int start, vector<string>& solution) {
    if (start == n) {
      ret_.emplace_back(solution);
      return;
    }
    for (int i = 0; i < n; ++i) {
      if (isSafe(start, i)) {
        solution[start][i] = 'Q';
        queen_col_[start] = i;
        solve(n, start + 1, solution);
        queen_col_[start] = -1;
        solution[start][i] = '.';
      }
    }
  }
};