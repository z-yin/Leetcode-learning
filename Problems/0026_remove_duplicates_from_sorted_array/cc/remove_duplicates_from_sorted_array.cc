#include <vector>
using namespace std;

// 16 ms, 10 MB. No erase but replace.
class Solution {
 public:
  int removeDuplicates(vector<int>& nums) {
    if (nums.size() < 2) {
      return nums.empty() ? 0 : 1;
    }
    int j = 0;
    for (int i = 0; i < nums.size() - 1; ++i) {
      if (nums[i] != nums[i + 1]) {
        nums[j] = nums[i];
        ++j;
      }
    }
    nums[j] = nums[nums.size() - 1];
    return j + 1;
  }
};