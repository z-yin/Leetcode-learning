#include <string>
#include <vector>
using namespace std;

// 24 ms	9.8 MB. Backtracing.
class Solution {
 public:
  bool res = false;

  bool exist(vector<vector<char>>& b, string word) {
    for (int i = 0; i < b.size(); ++i) {
      for (int j = 0; j < b[0].size(); ++j) {
        if (b[i][j] == word[0]) {
          help(b, i, j, word, 0);
          if (res) return true;
        }
      }
    }
    return res;
  }

  void help(vector<vector<char>>& b, int r, int c, string& w, int from) {
    if (from == w.size()) {
      res = true;
      return;
    }
    if (r < 0 || r >= b.size() || c < 0 || c >= b[0].size()) return;
    if (from < w.size() && b[r][c] == w[from]) {
      char tmp = b[r][c];
      b[r][c] = '0';
      help(b, r - 1, c, w, from + 1);  // up
      if (res) return;
      help(b, r + 1, c, w, from + 1);  // down
      if (res) return;
      help(b, r, c - 1, w, from + 1);  // left
      if (res) return;
      help(b, r, c + 1, w, from + 1);  // right
      if (res) return;
      b[r][c] = tmp;
    }
  }
};