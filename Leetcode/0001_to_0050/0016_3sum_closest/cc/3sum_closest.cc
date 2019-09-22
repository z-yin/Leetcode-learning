#include <algorithm>
#include <vector>
using namespace std;

// 4 ms, 8.7 MB. Two pointers and store the smallest diff.
class Solution {
 public:
  int threeSumClosest(vector<int>& nums, int target) {
    sort(nums.begin(), nums.end());
    int diff = INT_MAX;
    int ret;
    for (int i = 0; i < nums.size() - 2; ++i) {
      int res = target - nums[i];
      int j = i + 1;
      int k = nums.size() - 1;
      while (j != k) {
        int sum2 = nums[j] + nums[k];
        if (sum2 < res) {
          ++j;
        } else if (sum2 > res) {
          --k;
        } else {
          return target;
        }
        if (abs(res - sum2) < diff) {
          diff = abs(res - sum2);
          ret = nums[i] + sum2;
        }
      }
    }
    return ret;
  }
};