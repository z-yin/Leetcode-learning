#include <vector>
using namespace std;

// 4 ms, 9.4 MB. Hash table.
class Solution {
 public:
  bool isValidSudoku(vector<vector<char>> &board) {
    int row[9][10] = {}, col[9][10] = {}, box[3][3][10] = {};
    for (int i = 0; i < 9; ++i) {
      for (int j = 0; j < 9; ++j) {
        int digit = board[i][j] == '.' ? 0 : (board[i][j] - '0');
        if (digit != 0) {
          if (row[i][digit] || col[j][digit] || box[i / 3][j / 3][digit]) {
            return false;
          }
          row[i][digit] = col[j][digit] = box[i / 3][j / 3][digit] = 1;
        } else {
          if (row[i][digit] == 9 || col[j][digit] == 9 ||
              box[i / 3][j / 3][digit] == 9) {
            return false;
          }
          ++row[i][digit];
          ++col[j][digit];
          ++box[i / 3][j / 3][digit];
        }
      }
    }
    return true;
  }
};