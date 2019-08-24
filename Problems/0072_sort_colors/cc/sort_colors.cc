#include <vector>
using namespace std;

// 0 ms, 8.6 MB. Idea from quicksort
class Solution {
 public:
  void sortColors(vector<int>& nums) {
    int l = 0;
    int r = nums.size() - 1;
    // [l...lt] < 1, [lt+1...gt-1] == 1, [gt...r]
    int lt = l - 1;
    int gt = r + 1;
    int i = l;
    while (i < gt) {
      if (nums[i] < 1) {
        swap(nums[++lt], nums[i]);
        ++i;
      } else if (nums[i] > 1) {
        swap(nums[--gt], nums[i]);
      } else {
        ++i;
      }
    }
  }
};