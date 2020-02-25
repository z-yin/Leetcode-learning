#include <string>
using namespace std;

class Solution {
 public:
  int longestSubstring(string &s, int k) {
    int count[26]{0};
    for (auto c : s) {
      ++count[c - 'a'];
    }
    for (int i = 0; i < s.size(); ++i) {
      if (count[s[i] - 'a'] < k) {
        string s1 = s.substr(0, i);
        string s2 = s.substr(i + 1, s.size() - i - 1);
        return max(longestSubstring(s1, k),
                   longestSubstring(s2, k));
      }
    }
    return s.size();
  }
};