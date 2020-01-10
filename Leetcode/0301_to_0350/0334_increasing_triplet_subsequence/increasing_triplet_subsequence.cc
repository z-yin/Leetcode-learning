#include <limits>
#include <vector>
using namespace std;

// 0 ms	8.9 MB.
class Solution {
 public:
  bool increasingTriplet(vector<int>& nums) {
    if (nums.size() < 3) return false;

    int a, b;
    a = b = INT_MAX;
    for (int i : nums) {
      if (i > b)
        return true;
      else if (i > a)
        b = min(i, b);
      else
        a = i;
    }
    return false;
  }
};