#include <string>
using namespace std;

// 4 ms, 9.2 MB.
class Solution {
 public:
  string countAndSay(int n) {
    string ret = "1";
    while (n > 1) {
      --n;
      string next;
      char c = ret[0];
      int i = 1, cnt = 1;
      while (i < ret.size()) {
        if (ret[i] == c) {
          ++i;
          ++cnt;
        } else {
          next += to_string(cnt) + c;
          cnt = 1;
          c = ret[i];
          ++i;
        }
      }
      ret = next + to_string(cnt) + c;
    }
    return ret;
  }
};