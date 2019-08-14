#include <string>
#include <vector>
using namespace std;

// 4 ms, 8.8 MB. DP
class Solution {
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