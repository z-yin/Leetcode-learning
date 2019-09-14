#include <string>
#include <vector>
#include <algorithm>
using namespace std;

// 12 ms, 9 MB. DP
class Solution {
 public:
  int minDistance(string w1, string w2) {
    int sz1 = w1.size();
    int sz2 = w2.size();
    if (sz1 == 0 && sz2 == 0) return 0;
    
    vector<vector<int>> dp(2, vector<int>(sz1 + 1, 0));
    for (int i = 0; i <= sz2; ++i) {
      for (int j = 0; j <= sz1; ++j) {
        if (i != 0 || j != 0) {
          int mini_cost = INT_MAX;
          // right
          if (i > 0 && j > 0 && w1[j - 1] == w2[i - 1]) {
            mini_cost = dp[(i + 1) % 2][j - 1];
          }
          // replace
          if (i > 0 && j > 0) {
            mini_cost = min(mini_cost, dp[(i + 1) % 2][j - 1] + 1);
          }
          // delete
          if (i > 0) {
            mini_cost = min(mini_cost, dp[(i + 1) % 2][j] + 1);
          }
          // insert
          if (j > 0) {
            mini_cost = min(mini_cost, dp[i % 2][j - 1] + 1);
          }
          dp[i % 2][j] = mini_cost;
        }
      }
    }
    return dp[sz2 % 2][sz1];
  }
};