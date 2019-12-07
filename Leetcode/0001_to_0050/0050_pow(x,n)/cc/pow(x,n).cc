#include <algorithm>
using namespace std;

// 0 ms, 8.4 MB. Binary search.
class Solution {
 public:
  double myPow(double x, int n) {
    int sign = n > 0 ? 1 : -1;
    long long nn = abs((long long)n);
    double res = 1;
    while (nn) {
      if (nn % 2 == 1) res *= x;
      x *= x;
      nn /= 2;
    }
    if (sign == -1) res = 1 / res;
    return res;
  }
};