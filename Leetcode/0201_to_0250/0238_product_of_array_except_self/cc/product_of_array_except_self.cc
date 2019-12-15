#include <vector>
using namespace std;

// 40 ms	12.6 MB. O(1) space.
class Solution {
 public:
  vector<int> productExceptSelf(vector<int>& nums) {
    vector<int> res(nums);
    if (nums.empty()) return res;

    for (int i = 1; i < res.size(); ++i) res[i] *= res[i - 1];

    int prod = 1;
    for (int i = res.size() - 1; i > 0; --i) {
      res[i] = res[i - 1] * prod;
      prod *= nums[i];
    }
    res[0] = prod;
    return res;
  }
};