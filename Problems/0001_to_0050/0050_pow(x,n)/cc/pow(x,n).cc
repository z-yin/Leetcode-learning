#include <algorithm>
using namespace std;

// 0 ms, 8.4 MB. Binary search.
class Solution {
 public:
  double myPow(double x, int n) {
    bool negative = false;
    if (n < 0) {
      negative = true;
    }
    long long power = abs((long long)n);
    double res = 1;
    while (power > 0) {
      if (power % 2 == 0) {
        x *= x;
      } else {
        res *= x;
        if (power > 1) {
          x *= x;
        }
      }
      power /= 2;
    }
    if (negative) {
      res = 1 / res;
    }
    return res;
  }
};