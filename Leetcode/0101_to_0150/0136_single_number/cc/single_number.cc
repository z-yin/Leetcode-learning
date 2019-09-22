#include <vector>
using namespace std;

// 12 ms, 9.7 MB. Bit manipulation
class Solution {
 public:
  int singleNumber(vector<int>& nums) {
    int res = 0;
    for (auto &e : nums) {
      res ^= e;
    }
    return res;
  }
};