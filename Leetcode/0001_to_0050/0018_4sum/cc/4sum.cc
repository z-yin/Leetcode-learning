#include <vector>
using namespace std;

// 8 ms, 8.9 MB. Two pointers. Skip duplicates. Early pruning.
class Solution {
 public:
  vector<vector<int>> fourSum(vector<int>& nums, int target) {
    sort(nums.begin(), nums.end());
    vector<vector<int>> ret;
    int len = nums.size();
    if (len < 4) {
      return ret;
    }
    for (int i = 0; i < len - 3; ++i) {
      if (i != 0 && nums[i] == nums[i - 1]) {
        continue;
      }
      // Pruning. Stop on too small or too large target.
      if (nums[i] + nums[len - 3] + nums[len - 2] + nums[len - 1] < target) {
        continue;
      }
      if (nums[i] + nums[i + 1] + nums[i + 2] + nums[i + 3] > target) {
        break;
      }
      for (int j = i + 1; j < len - 2; ++j) {
        if (j != i + 1 && nums[j] == nums[j - 1]) {
          continue;
        }
        int res = target - nums[i] - nums[j];
        int k = j + 1;
        int l = len - 1;
        while (k != l) {
          int sum2 = nums[k] + nums[l];
          if (sum2 < res) {
            ++k;
            while (k != l && nums[k] == nums[k - 1]) {
              ++k;
            }
          } else if (sum2 > res) {
            --l;
            while (k != l && nums[l] == nums[l + 1]) {
              --l;
            }
          } else {
            ret.emplace_back(vector<int>{nums[i], nums[j], nums[k], nums[l]});
            ++k;
            while (k != l && nums[k] == nums[k - 1]) {
              ++k;
            }
          }
        }
      }
    }
    return ret;
  }
};