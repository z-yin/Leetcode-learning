#include <string>
using namespace std;

// 0 ms	8.3 MB. DP. Space O(3).
class Solution {
 public:
  int numDecodings(string s) {
    if (s[0] == '0') 
      return 0;
    int f[3] = {0};
    f[0] = f[1] = 1;
    for (int i = 2; i <= s.size(); ++i) {
      f[i % 3] = 0; // reset
      if (s[i - 1] - '0' != 0) f[i % 3] = f[(i - 1) % 3];
      if (s[i - 2] - '0' == 1
          || (s[i - 2] - '0' == 2 && s[i - 1] - '0' <= 6)) {
        f[i % 3] += f[(i - 2) % 3];
      }
    }
    return f[s.size() % 3];
  }
};