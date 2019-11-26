#include <vector>
using namespace std;

// 60 ms, 12 MB.
class Solution {
 public:
  bool searchMatrix(vector<vector<int>>& matrix, int target) {
    if (matrix.empty() || matrix[0].empty()) return false;
    int r = matrix.size() - 1;
    int c = 0;
    while (r >= 0 && c < matrix[0].size()) {
      if (matrix[r][c] == target) return true;
      if (matrix[r][c] < target) ++c;
      else --r;
    }
    return false;
  }
};