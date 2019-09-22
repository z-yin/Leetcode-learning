#include <string>
#include <unordered_map>
using namespace std;

// 16 ms, 10.9 MB. Two pointers and Hashmap.
class Solution {
 public:
  int lengthOfLongestSubstring(string s) {
    unordered_map<char, int> idx;
    int max_len = 0;
    int i = 0, j = 0;
    while (j < s.size()) {
      if (!idx.count(s[j]) || idx[s[j]] < i) {
        idx[s[j]] = j;
      } else {
        max_len = max(max_len, j - i);
        i = idx[s[j]] + 1;
        idx[s[j]] = j;
      }
      ++j;
    }
    return max(max_len, j - i);
  }
};