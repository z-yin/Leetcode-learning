#include <vector>
using namespace std;

// 0 ms, 8.7 MB. In-place hash table. Negative mark.
class Solution {
 public:
  int firstMissingPositive(vector<int>& nums) {
    if (nums.empty()) {
      return 1;
    }
    // put all non-positive into right side
    int i = 0, j = nums.size() - 1;
    while (i < j && nums[j] <= 0) {
      --j;
    }
    while (i < j) {
      if (nums[i] <= 0) {
        swap(nums[i], nums[j]);
        --j;
        while (i < j && nums[j] <= 0) {
          --j;
        }
      }
      ++i;
    }
    // mark appearance
    int size = nums[i] > 0 ? i + 1 : i;
    for (i = 0; i < size; ++i) {
      if (abs(nums[i]) - 1 < size && nums[abs(nums[i]) - 1] > 0) {
        nums[abs(nums[i]) - 1] *= -1;
      }
    }
    for (i = 0; i < size && nums[i] < 0; ++i) {
    }
    return i + 1;
  }
};