#include <algorithm>
#include <vector>
using namespace std;

// 4 ms, 8.6 MB
class Solution {
 public:
  int rob(vector<int>& nums) {
    if (nums.size() < 2) {
      return nums.size() == 0 ? 0 : nums[0];
    }
    return max(rob(nums, 0, nums.size() - 2), rob(nums, 1, nums.size() - 1));
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