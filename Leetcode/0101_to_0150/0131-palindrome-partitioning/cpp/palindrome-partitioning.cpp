#include <vector>
#include <string>
using namespace std;

// 12 ms, 13.4 MB. Backtracking
class Solution1 {
private:
    vector<vector<string>> ret;

    bool __isPalin (const string &str, int left, int right) {
        while (left < right)
            if (str[left++] != str[right--])
                return false;
        return true;
    }

    void __partition (const string &str, int start, vector<string> &s) {
        
        if (start == str.size()) {
            ret.emplace_back(s);
            return;
        }

        int i = 1; // number of characters used
        while (start + i <= str.size()) {
            if (__isPalin(str, start, start + i - 1)) {
                s.emplace_back( str.substr(start, i) );
                __partition(str, start + i, s);
                s.pop_back();
            }
            ++ i;
        }
    }
public:
    vector<vector<string>> partition(string s) {

        ret.clear();
        if (s.empty()) return ret;

        vector<string> tmp;
        tmp.clear();
        __partition(s, 0, tmp);
        return ret;
    }
};

// 16 ms	13.7 MB. DP and backtracking.
class Solution2 {
 public:
  vector<vector<string>> res;
  vector<vector<bool>> dp;
  
  vector<vector<string>> partition(string s) {
    if (s.empty()) return res;
    
    int n = s.size();
    dp = vector<vector<bool>>(n + 1, vector<bool>(n + 1, false));
    for (int i = 0; i <= n; ++i) dp[i][i] = true;
    for (int i = 0; i < n; ++i) dp[i][i + 1] = true;
    
    for (int j = 2; j <= n; ++j) {
      int k = 0;
      while (j + k <= n) {
        dp[k][j + k] = s[k] == s[j + k - 1] && dp[k + 1][j + k - 1];
        ++k;
      }
    }
    
    vector<string> v;
    dfs(s, 0, v);
    return res;
  }
  
  void dfs(string &s, int from, vector<string> &v) {
    if (from == s.size()) {
      res.emplace_back(v);
      return;
    }
    
    for (int to = from + 1; to <= s.size(); ++to) {
      if (dp[from][to]) {
        v.emplace_back(s.substr(from, to - from));
        dfs(s, to, v);
        v.pop_back();
      }
    }
  }
};
