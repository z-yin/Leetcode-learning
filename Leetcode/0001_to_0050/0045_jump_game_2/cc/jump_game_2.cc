#include <climits>
#include <vector>
using namespace std;

// Time limit exceeded. Backtracking.
class Solution1 {
 public:
  int jump(vector<int> &nums) {
    jump(nums, 0, 0);
    return min_num_;
  }

 private:
  int min_num_ = INT_MAX;

  void jump(const vector<int> &nums, int start, int num) {
    if (start == nums.size() - 1) {
      min_num_ = num;
      return;
    }

    if (num < min_num_ && start < nums.size()) {
      for (int i = nums[start]; i >= 1; --i) {
        jump(nums, start + i, num + 1);
      }
    }
  }
};

// Time limit exceeded (less than Solution 1). DP.
class Solution2 {
 public:
  int jump(vector<int> &nums) {
    vector<int> dp(nums.size(), 0);
    for (int i = 1; i < nums.size(); ++i) {
      int min_step = INT_MAX;
      for (int j = 1; j <= i; ++j) {
        if (nums[i - j] >= j) {
          min_step = min(min_step, dp[i - j] + 1);
        }
      }
      dp[i] = min_step;
    }
    return dp[nums.size() - 1];
  }
};

// 12 ms, 10.1 MB. Greedy.
class Solution3 {
 public:
  int jump(vector<int> &nums) {
    int ret = 0, i = 0, cur = 0;
    while (cur < nums.size() - 1) {
      ++ret;
      int pre = cur;
      for (; i <= pre; ++i) {
        cur = max(cur, i + nums[i]);
      }
    }
    return ret;
  }
};
