#include <string>
#include <vector>
using namespace std;

// 12 ms, 8.7 MB. DP.
class Solution {
 public:
  int longestCommonSubsequence(string text1, string text2) {
    vector<vector<int>> dp(2, vector<int>(text2.size() + 1, 0));
    for (int i = 1; i <= text1.size(); ++i) {
      for (int j = 1; j <= text2.size(); ++j) {
        if (text1[i - 1] == text2[j - 1]) {
          dp[i % 2][j] = dp[(i + 1) % 2][j - 1] + 1;
        } else {
          dp[i % 2][j] = max(dp[(i + 1) % 2][j], dp[i % 2][j - 1]);
        }
      }
    }
    return dp[text1.size() % 2][text2.size()];
  }
};