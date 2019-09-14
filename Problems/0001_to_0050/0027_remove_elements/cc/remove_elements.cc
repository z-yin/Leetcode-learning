#include <vector>
using namespace std;

// 0 ms, 8.7 MB.
class Solution {
 public:
  int removeElement(vector<int>& nums, int val) {
    int j = 0;
    for (int i = 0; i < nums.size(); ++i) {
      if (nums[i] != val) {
        nums[j] = nums[i];
        ++j;
      }
    }
    return j;
  }
};