#include <string>
using namespace std;

// 0 ms, 8.2 MB.
class Solution {
 public:
  string convertToBase7(int num) {
    bool neg = num < 0 ? true : false;
    num = neg ? -num : num;
    string res = num == 0 ? "0" : "";
    while (num > 0) {
      res = to_string(num % 7) + res;
      num /= 7;
    }
    return neg ? "-" + res : res;
  }
};