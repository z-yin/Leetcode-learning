#include <vector>
using namespace std;

// 4 ms	8.6 MB. DP and binary search. Time nlog(n)
class Solution {
 public:
  int lengthOfLIS(vector<int>& nums) {
    vector<int> dp(nums.size(), 0);
    auto last = dp.begin();
    for (int& e : nums) {
      auto pos = lower_bound(dp.begin(), last, e);
      *pos = e;
      if (pos == last) ++last;
    }

    return last - dp.begin();
  }
};