#include <algorithm>
#include <vector>
using namespace std;

// 8 ms, 8.5 MB.
class Solution {
 public:
  void nextPermutation(vector<int>& nums) {
    int i;
    for (i = nums.size() - 1; i > 0 && nums[i - 1] >= nums[i]; --i) {
    }
    if (i == 0) {
      sort(nums.begin(), nums.end());
      return;
    }
    int min_num = INT_MAX;
    int min_idx = -1;
    for (int j = i; j < nums.size(); ++j) {
      if (nums[j] > nums[i - 1] && nums[j] < min_num) {
        min_num = nums[j];
        min_idx = j;
      }
    }
    swap(nums[i - 1], nums[min_idx]);
    sort(nums.begin() + i, nums.end());
  }
};