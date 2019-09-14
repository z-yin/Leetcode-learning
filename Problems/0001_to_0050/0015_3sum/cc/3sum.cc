#include <vector>
#include <algorithm>
using namespace std;

// 96 ms, 14.5 MB. Two pointers.
class Solution {
 public:
  vector<vector<int>> threeSum(vector<int>& nums) {
    sort(nums.begin(), nums.end());
    vector<vector<int>> ret;
    
    int len = nums.size();
    for (int i = 0; i < len - 2 && nums[i] <= 0; ++i) {
      if (i != 0 && nums[i] == nums[i - 1]) continue;
      int j = i + 1;
      int k = len - 1;
      while (j < k && nums[k] >= 0) {
        int sum3 = nums[i] + nums[j] + nums[k];
        if (sum3 == 0) {
          ret.emplace_back(vector<int>{nums[i], nums[j], nums[k]});
          ++j;
          while (j < k && nums[j] == nums[j - 1]) {
            ++j;
          }
        } else if (sum3 < 0) {
          ++j;
        } else {
          --k;
        }
      }
    }
    return ret;
  }
};