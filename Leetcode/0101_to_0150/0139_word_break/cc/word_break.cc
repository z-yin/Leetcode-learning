#include <string>
#include <vector>
using namespace std;

// 4 ms, 8.8 MB. DP
class Solution1 {
 public:
  bool wordBreak(string s, vector<string>& wordDict) {
    can_ = vector<int>(s.size() + 1, -1);
    can_[0] = 1;
    return TryBreak(s, wordDict, s.size()) == 1;
  }

 private:
  vector<int> can_;  // can be segmented

  int TryBreak(const string& s, const vector<string>& wordDict,
               const int& end) {
    if (can_[end] != -1) {
      return can_[end];
    }
    for (const auto& word : wordDict) {
      if (end >= word.size() &&
          word == s.substr(end - word.size(), word.size())) {
        can_[end] = TryBreak(s, wordDict, end - word.size());
      }
      if (can_[end] == 1) {
        break;
      }
    }
    if (can_[end] == -1) {
      can_[end] = 0;
    }
    return can_[end];
  }
};

// 0 ms	8.6 MB. DP.
class Solution2 {
 public:
  bool wordBreak(string s, vector<string>& wordDict) {
    vector<bool> dp(s.size() + 1, false);
    dp[0] = true;

    for (int i = 1; i < s.size() + 1; ++i) {
      for (auto& w : wordDict) {
        if (w.size() <= i && match(s, i - w.size(), i - 1, w) &&
            dp[i - w.size()]) {
          dp[i] = true;
          break;
        }
      }
    }
    return dp[s.size()];
  }

  bool match(string& s, int i, int j, string& t) {
    for (int k = 0; i <= j; ++k, ++i)
      if (t[k] != s[i]) return false;
    return true;
  }
};
