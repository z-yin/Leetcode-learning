#include <algorithm>
#include <vector>
using namespace std;

// 8 ms, 9.4 MB. Divide and conquer.
class Solution {
 private:
  int max3(int e1, int e2, int e3) { return max(e1, max(e2, e3)); }

  int maxCrossSubArray(const vector<int>& nums, int l, int m, int r) {
    int sum = 0;
    int left_sum = INT_MIN;

    for (int i = m; i >= l; --i) {
      sum += nums[i];
      if (sum > left_sum) {
        left_sum = sum;
      }
    }

    sum = 0;
    int right_sum = INT_MIN;

    for (int i = m + 1; i <= r; ++i) {
      sum += nums[i];
      if (sum > right_sum) {
        right_sum = sum;
      }
    }
    return left_sum + right_sum;
  }

  int maxSubArray(const vector<int>& nums, int l, int r) {
    if (l == r) {
      return nums[l];
    }
    int mid = (l + r) / 2;

    return max3(maxSubArray(nums, l, mid), maxSubArray(nums, mid + 1, r),
                maxCrossSubArray(nums, l, mid, r));
  }

 public:
  int maxSubArray(vector<int>& nums) {
    int nums_size = nums.size();
    if (nums_size == 0) {
      return 0;
    }
    return maxSubArray(nums, 0, nums_size - 1);
  }
};