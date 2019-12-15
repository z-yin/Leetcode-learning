#include <algorithm>
#include <climits>
#include <cmath>
#include <vector>
using namespace std;

// 100 ms	11.4 MB. DP.
class Solution1 {
 public:
  int numSquares(int n) {
    vector<int> dp(n + 1, INT_MAX);
    dp[0] = 0;
    for (int i = 1; i <= n; ++i) {
      for (int j = 1; j * j <= i; ++j) {
        dp[i] = min(dp[i], dp[i - j * j] + 1);
      }
    }
    return dp[n];
  }
};

// 0 ms	8.3 MB. Lagrange’s Four-Square Theorem.
class Solution2 {
 public:
  bool isSquare(int n) {
    int sqrt_n = sqrt(n);
    return n == (sqrt_n * sqrt_n);
  }

  int numSquares(int n) {
    if (isSquare(n)) return 1;

    while ((n & 3) == 0) n >>= 2;
    if ((n & 7) == 7) return 4;

    int i = sqrt(n);
    for (int j = 0; j <= i; ++j)
      if (isSquare(n - j * j)) return 2;

    return 3;
  }
};
