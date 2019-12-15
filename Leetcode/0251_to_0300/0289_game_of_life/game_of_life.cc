#include <algorithm>
#include <vector>
using namespace std;

// 0 ms	8.5 MB. Intermediate value for update. O(1) space.
class Solution {
 public:
  void gameOfLife(vector<vector<int>>& b) {
    if (b.empty()) return;
    for (int i = 0; i < b.size(); ++i) {
      for (int j = 0; j < b[0].size(); ++j) {
        int cnt = numsOfLive(b, i, j);
        if (abs(b[i][j]) == 1) {
          if (cnt < 2 || cnt > 3) b[i][j] = -1;
        } else {
          if (cnt == 3) b[i][j] = 2;
        }
      }
    }

    for (auto& v : b) {
      for (int& i : v) {
        if (i == -1)
          i = 0;
        else if (i == 2)
          i = 1;
      }
    }
  }

  int numsOfLive(vector<vector<int>>& b, int i, int j) {
    int cnt = 0;
    if (i > 0 && abs(b[i - 1][j]) == 1) ++cnt;
    if (i < b.size() - 1 && abs(b[i + 1][j]) == 1) ++cnt;
    if (j > 0 && abs(b[i][j - 1]) == 1) ++cnt;
    if (j < b[0].size() - 1 && abs(b[i][j + 1]) == 1) ++cnt;
    if (i > 0 && j > 0 && abs(b[i - 1][j - 1]) == 1) ++cnt;
    if (i > 0 && j < b[0].size() - 1 && abs(b[i - 1][j + 1]) == 1) ++cnt;
    if (i < b.size() - 1 && j > 0 && abs(b[i + 1][j - 1]) == 1) ++cnt;
    if (i < b.size() - 1 && j < b[0].size() - 1 && abs(b[i + 1][j + 1]) == 1)
      ++cnt;
    return cnt;
  }
};