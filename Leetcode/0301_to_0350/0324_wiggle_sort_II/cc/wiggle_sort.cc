#include <vector>
using namespace std;

// Time O(nlog(n)). Space O(n). 72 ms	11.5 MB.
class Solution {
 public:
  void wiggleSort(vector<int>& nums) {
    vector<int> tmp(nums);
    sort(tmp.begin(), tmp.end());
    
    for (int i = 0, j = (nums.size() + 1) / 2, k = nums.size(); i < nums.size(); ++i) {
      nums[i] = i & 1 ? tmp[--k] : tmp[--j];
    }
  }
};