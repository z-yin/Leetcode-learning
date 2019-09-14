#include <vector>
using namespace std;

// 12 ms, 9.8 MB. Bit manipulation.
class Solution {
 public:
  vector<int> singleNumber(vector<int>& nums) {
    int nums_xor = 0;
    for (auto &num : nums) {
      nums_xor ^= num;
    }
    int mask = 1;
    while ((mask & nums_xor) == 0) {
      mask <<= 1;
    }
    int a = 0, b = 0;
    for (auto &num : nums) {
      if (num & mask) {
        a ^= num;
      } else {
        b ^= num;
      }
    }
    return {a, b};
  }
};