// 0 ms, 8.2 MB. Binary search. Attention on boundary condition.
class Solution {
 public:
  int mySqrt(int x) {
    if (x <= 1) return x == 0 ? 0 : 1;
    int l = 1, r = x;
    long long mid;
    while (l < r) {
      mid = ((long long)l + r + 1) / 2;  // stick to right
      long long square = mid * mid;
      if (square < x) {
        l = (int)mid;  // infinite loop if mid is not stick to right
      } else if (square > x) {
        r = (int)mid - 1;
      } else {
        return (int)mid;
      }
    }
    return l;
  }
};