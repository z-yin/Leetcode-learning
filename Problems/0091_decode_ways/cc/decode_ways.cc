#include <string>
using namespace std;

// 4ms, 8,5 MB. DP
class Solution {
 public:
  int numDecodings(string s) {
    int size = s.size();
    if (size == 0 || s[0] == '0') {
      return 0;
    }
    int *memo = new int[size + 1];
    memo[0] = 1;
    memo[1] = 1;
    
    for (int i = 2; i <= size; ++i) {
      memo[i] = 0;
      if (s[i - 1] != '0') {
        memo[i] = memo[i - 1];
      }
      if (s[i - 2] == '1' || (s[i - 2] == '2' && s[i - 1] < '7')) {
        memo[i] += memo[i - 2];
      }
    }
    return memo[size];
  }
};