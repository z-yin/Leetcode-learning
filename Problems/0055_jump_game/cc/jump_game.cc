#include <vector>
using namespace std;

// 12 ms, 9.9 MB. Greedy.
class Solution {
 public:
  bool canJump(vector<int>& nums) {
    int farest = nums[0];
    for (int i = 0; i < nums.size(); ++i) {
      if (farest >= nums.size() - 1) {
        return true;
      }
      if (i >= farest && nums[i] == 0) {
        return false;
      }
      if (i + nums[i] > farest) {
        farest = i + nums[i];
      }
    }
    return false;
  }
};