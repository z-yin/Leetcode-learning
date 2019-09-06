#include <string>
#include <vector>
using namespace std;

// 116 ms, 13.6 MB. DP. Time and space: O(mn).
class Solution1 {
 public:
  bool isMatch(string s, string p) {
    vector<vector<bool>> dp(s.size() + 1, vector<bool>(p.size() + 1, false));
    dp[0][0] = true;
    int t = 1;
    while (p[t - 1] == '*') {
      dp[0][t] = true;
      ++t;
    }
    for (int i = 1; i <= s.size(); ++i) {
      for (int j = 1; j <= p.size(); ++j) {
        if (p[j - 1] == '*') {
          dp[i][j] =
              dp[i][j] || dp[i - 1][j - 1] || dp[i - 1][j] || dp[i][j - 1];
        } else if (s[i - 1] == p[j - 1] || p[j - 1] == '?') {
          dp[i][j] = dp[i][j] || dp[i - 1][j - 1];
        }
      }
    }
    return dp[s.size()][p.size()];
  }
};

// 4 ms, 8.7 MB. Backtracking and greedy.
class Solution2 {
 public:
  bool isMatch(string s, string p) {
    int i = 0, j = 0, i_star = -1, j_star = -1;
    while (i < s.size()) {
      if (s[i] == p[j] || p[j] == '?') {
        ++i;
        ++j;
      } else if (p[j] == '*') {
        i_star = i;
        j_star = j;
        ++j;
      } else if (i_star != -1) {
        i = ++i_star;
        j = j_star + 1;
      } else {
        return false;
      }
    }
    while (j < p.size() && p[j] == '*') {
      ++j;
    }
    return j == p.size();
  }
};