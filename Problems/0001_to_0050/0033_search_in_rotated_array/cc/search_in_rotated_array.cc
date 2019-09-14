#include <vector>
using namespace std;

// 4 ms, 8.7 MB. Two binary searches, one for pivot and one for target.
class Solution {
 public:
  int search(vector<int>& nums, int target) {
    if (nums.empty()) {
      return -1;
    }
    int left = nums[0], right = nums[nums.size() - 1];
    if (left <= right) {
      return binarySearch(nums, target, 0, nums.size() - 1);
    }

    int l = 0, r = nums.size() - 1;
    while (l < r) {
      int m = (l + r) / 2;
      if (nums[m] >= left) {
        l = m + 1;
      } else {
        r = m;
      }
    }
    int ret;
    if (target >= left) {
      ret = binarySearch(nums, target, 0, l - 1);
    } else {
      ret = binarySearch(nums, target, l, nums.size() - 1);
    }
    return ret;
  }

 private:
  int binarySearch(const vector<int>& nums, int target, int l, int r) {
    while (l <= r) {
      int m = (l + r) / 2;
      if (target < nums[m]) {
        r = m - 1;
      } else if (target > nums[m]) {
        l = m + 1;
      } else {
        return m;
      }
    }
    return -1;
  }
};