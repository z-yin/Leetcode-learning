#include <string>
using namespace std;

// 4 ms, 8.7 MB. Hash table.
class Solution {
 public:
  int longestPalindrome(string s) {
    int count[58] = {0}; // 6 symbols between 'Z' and 'a'
    for (const auto& c : s) {
      ++count[c - 'A'];
    }
    int max_length = 0;
    int max_odds = 0;
    for (int i = 0; i < 58; ++i) {
      if (count[i] % 2 == 0) {
        max_length += count[i];
      } else if (count[i] > max_odds) {
        max_length += count[i] - min(1, max_odds);
        max_odds = count[i];
      } else {
        max_length += count[i] - 1;
      }
    }
    return max_length;
  }
};