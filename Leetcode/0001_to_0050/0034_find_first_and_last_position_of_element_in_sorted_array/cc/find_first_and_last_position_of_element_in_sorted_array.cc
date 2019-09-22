#include <vector>
using namespace std;

// 8 ms, 10.1 MB. Two binary search for left and right endpoints.
class Solution {
 public:
  vector<int> searchRange(vector<int>& nums, int target) {
    vector<int> ret{-1, -1};
    if (nums.empty() || target < nums[0] || target > *(nums.end() - 1)) {
      return ret;
    }

    int l = 0, r = nums.size() - 1;
    while (l < r) {
      int m = (l + r) / 2;
      if (target - 0.5 < nums[m]) {
        r = m;
      } else {
        l = m + 1;
      }
    }
    if (nums[l] != target) {
      return ret;
    }
    ret[0] = l;  // or r

    r = nums.size() - 1;
    while (l < r) {
      int m = (l + r + 1) / 2;
      if (target + 0.5 > nums[m]) {
        l = m;
      } else {
        r = m - 1;
      }
    }
    ret[1] = r;  // or l
    return ret;
  }
};