#include <algorithm>
#include <vector>
using namespace std;

// 4 ms, 9.6 MB.
class Solution {
 public:
  int maxProfit(vector<int>& prices) {
    int n = prices.size();
    if (n == 0 || n == 1) {
      return 0;
    }

    int min_price = prices[0];
    int result = 0;
    for (int i = 1; i < n; ++i) {
      result = max(result, prices[i] - min_price);
      min_price = min(min_price, prices[i]);
    }
    return result;
  }
};