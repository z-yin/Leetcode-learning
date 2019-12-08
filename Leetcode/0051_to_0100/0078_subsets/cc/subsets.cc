#include <vector>
using namespace std;

// 4 ms	13 MB. Backtracing.
class Solution {
 public:
  vector<vector<int>> res;
  
  vector<vector<int>> subsets(vector<int>& nums) {
    vector<int> s;
    help(nums, 0, s);
    return res;
  }
  
  void help(vector<int>& nums, int from, vector<int> &s) {
    if (from == nums.size()) {
      res.emplace_back(s);
      return;
    }
    if (from < nums.size()) {
      s.emplace_back(nums[from]);
      help(nums, from + 1, s);
      s.pop_back();
      
      help(nums, from + 1, s);
    }
  }
};