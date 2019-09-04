#include <vector>
using namespace std;

// 24 ms, 14.1 MB. BP without skipping.
class Solution1 {
 public:
  void solveSudoku(vector<vector<char>>& board) {
    bool row[9][10] = {false}, col[9][10] = {false}, box[3][3][10] = {false};
    for (int i = 0; i < 9; ++i) {
      for (int j = 0; j < 9; ++j) {
        int digit = board[i][j] == '.' ? 0 : (board[i][j] - '0');
        if (digit != 0) {
          row[i][digit] = col[j][digit] = box[i / 3][j / 3][digit] = true;
        }
      }
    }
    solve(board, row, col, box, 0, 0);
  }

 private:
  bool solve(vector<vector<char>>& board, bool row[][10], bool col[][10],
             bool box[][3][10], int i, int j) {
    if (i == 9) {
      return true;
    }
    if (board[i][j] == '.') {
      vector<int> option;
      for (int k = 1; k <= 9; ++k) {
        if (!row[i][k] && !col[j][k] && !box[i / 3][j / 3][k]) {
          option.emplace_back(k);
        }
      }
      for (int k : option) {
        board[i][j] = k + '0';
        row[i][k] = col[j][k] = box[i / 3][j / 3][k] = true;
        if (solve(board, row, col, box, i + (j + 1) / 9, (j + 1) % 9)) {
          return true;
        }
        row[i][k] = col[j][k] = box[i / 3][j / 3][k] = false;
        board[i][j] = '.';
      }
    } else {
      return solve(board, row, col, box, i + (j + 1) / 9, (j + 1) % 9);
    }
    return false;
  }
};

// 24 ms, 11.2 MB. BP, skipping not '.'.
class Solution2 {
 public:
  void solveSudoku(vector<vector<char>>& board) {
    bool row[9][10] = {false}, col[9][10] = {false}, box[3][3][10] = {false};
    for (int i = 0; i < 9; ++i) {
      for (int j = 0; j < 9; ++j) {
        int digit = board[i][j] == '.' ? 0 : (board[i][j] - '0');
        if (digit != 0) {
          row[i][digit] = col[j][digit] = box[i / 3][j / 3][digit] = true;
        }
      }
    }
    int i = 0, j = 0;
    while (board[i][j] != '.') {
      i += (j + 1) / 9;
      j = (j + 1) % 9;
    }
    solve(board, row, col, box, i, j);
  }

 private:
  bool solve(vector<vector<char>>& board, bool row[][10], bool col[][10],
             bool box[][3][10], int i, int j) {
    if (i == 9) {
      return true;
    }
    // determine the next '.'
    int ii = i + (j + 1) / 9;
    int jj = (j + 1) % 9;
    while (ii < 9 && board[ii][jj] != '.') {
      ii += (jj + 1) / 9;
      jj = (jj + 1) % 9;
    }

    vector<int> option;
    for (int k = 1; k <= 9; ++k) {
      if (!row[i][k] && !col[j][k] && !box[i / 3][j / 3][k]) {
        option.emplace_back(k);
      }
    }

    for (int k : option) {
      board[i][j] = k + '0';
      row[i][k] = col[j][k] = box[i / 3][j / 3][k] = true;
      if (solve(board, row, col, box, ii, jj)) {
        return true;
      }
      row[i][k] = col[j][k] = box[i / 3][j / 3][k] = false;
      board[i][j] = '.';
    }
    return false;
  }
};

// 0 ms, 8.7 MB. BP.
// Without 'option' variable, no need to store '.' so 10 -> 9 and other minor
// changes but increase performance.
class Solution3 {
 public:
  void solveSudoku(vector<vector<char>>& board) {
    for (int i = 0; i < 9; ++i) {
      for (int j = 0; j < 9; ++j) {
        if (board[i][j] != '.') {
          int k = board[i][j] - '1';
          row_[i][k] = col_[j][k] = box_[i / 3][j / 3][k] = true;
        }
      }
    }
    int i = 0, j = 0;
    while (board[i][j] != '.') {
      i += (j + 1) / 9;
      j = (j + 1) % 9;
    }
    solve(board, i, j);
  }

 private:
  bool row_[9][9] = {false}, col_[9][9] = {false}, box_[3][3][9] = {false};

  bool solve(vector<vector<char>>& board, int i, int j) {
    if (i == 9) {
      return true;
    }
    // determine the next '.'
    int ii = i + (j + 1) / 9;
    int jj = (j + 1) % 9;
    while (ii < 9 && board[ii][jj] != '.') {
      ii += (jj + 1) / 9;
      jj = (jj + 1) % 9;
    }

    for (int k = 0; k < 9; ++k) {
      if (!row_[i][k] && !col_[j][k] && !box_[i / 3][j / 3][k]) {
        board[i][j] = k + '1';
        row_[i][k] = col_[j][k] = box_[i / 3][j / 3][k] = true;
        if (solve(board, ii, jj)) {
          return true;
        }
        row_[i][k] = col_[j][k] = box_[i / 3][j / 3][k] = false;
        board[i][j] = '.';
      }
    }
    return false;
  }
};