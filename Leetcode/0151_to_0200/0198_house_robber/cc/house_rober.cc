#include <algorithm>
#include <vector>
using namespace std;

// 0 ms, 8.9 MB. DP
class Solution1 {
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

// 0 ms, 8.6 MB
class Solution2 {
 public:
  int rob(vector<int>& nums) {
    if (nums.size() < 2) {
      return nums.size() == 0 ? 0 : nums[0];
    }
    return rob(nums, 0, nums.size() - 1);
  }

 private:
  int rob(const vector<int>& nums, const int& start, const int& end) {
    int rob_even = 0;
    int rob_odd = 0;
    int n = end - start + 1;
    for (int i = start; i <= end; ++i) {
      if (i % 2 == 0) {
        rob_even = max(rob_odd, rob_even + nums[i]);
      } else {
        rob_odd = max(rob_even, rob_odd + nums[i]);
      }
    }
    return max(rob_even, rob_odd);
  }
};

// 0 ms, 8.4 MB
class Solution3 {
 public:
  int rob(vector<int>& nums) {
    if (nums.size() < 2) {
      return nums.size() == 0 ? 0 : nums[0];
    }
    return rob(nums, 0, nums.size() - 1);
  }

 private:
  int rob(const vector<int>& nums, const int& start, const int& end) {
    int rob = 0, not_rob = 0;
    int pre_rob, pre_not_rob;
    for (int i = start; i <= end; ++i) {
      pre_rob = rob;
      pre_not_rob = not_rob;
      rob = not_rob + nums[i];
      not_rob = max(pre_not_rob, pre_rob);
    }
    return max(rob, not_rob);
  }
};