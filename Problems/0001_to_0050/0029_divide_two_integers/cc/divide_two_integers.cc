#include <algorithm>
#include <climits>
using namespace std;

// 0 ms, 8.1 MB. Left shift and right shift. Binary search.
class Solution {
 public:
  int divide(int dividend, int divisor) {
    int sign = 1;
    if ((dividend > 0 && divisor < 0) || (dividend < 0 && divisor > 0)) {
      sign = -1;
    }
    long long abs_dividend = abs((long long)dividend);
    long long abs_divisor = abs((long long)divisor);

    long long quotient = 0;
    while (abs_dividend >= abs_divisor) {
      long long curr_divisor = abs_divisor;
      long long curr_quotient = 1;
      while (abs_dividend >= curr_divisor) {
        curr_divisor <<= 1;
        curr_quotient <<= 1;
      }
      quotient += curr_quotient >> 1;
      abs_dividend -= curr_divisor >> 1;
    }

    if (sign == -1) {
      quotient = -quotient;
    }
    return min((long long)INT_MAX, max((long long)INT_MIN, quotient));
  }
};