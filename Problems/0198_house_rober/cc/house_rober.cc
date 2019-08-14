#include <algorithm>
#include <vector>
using namespace std;

// 0 ms, 8.9 MB. DP
class Solution {
 public:
  int rob(vector<int>& nums) {
    if (nums.size() < 2) {
      return nums.empty() ? 0 : nums[0];
    }
    memo_ = vector<int>(nums.size() + 1, -1);
    memo_[0] = 0;
    memo_[1] = nums[0];
    return TryRob(nums, nums.size());
  }

 private:
  vector<int> memo_;  // store max money that can be stoled in [0...end] house

  int TryRob(const vector<int>& nums, const int& end) {
    if (memo_[end] != -1) {
      return memo_[end];
    }
    memo_[end] =
        max(TryRob(nums, end - 1), TryRob(nums, end - 2) + nums[end - 1]);
    return memo_[end];
  }
};