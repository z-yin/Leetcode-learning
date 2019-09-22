#include <vector>
using namespace std;

// 4 ms, 9 MB. Binary search.
class Solution {
 public:
  int searchInsert(vector<int>& nums, int target) {
    int l = 0, r = nums.size() - 1;
    while (l < r) {
      int m = (l + r) / 2;
      if (target < nums[m]) {
        r = m;
      } else if (target > nums[m]) {
        l = m + 1;
      } else {
        return m;
      }
    }
    if (l == nums.size() - 1 && target > *(nums.end() - 1)) {
      return l + 1;
    }
    return l;  // or r;
  }
};