#include <vector>
#include <unordered_map>
using namespace std;

// 4 ms, 9.6 MB. Using map.
class Solution {
 public:
  vector<int> twoSum(vector<int>& numbers, int target) {
    unordered_map<int, int> mp;
    int i;
    int residual;
    int len = numbers.size();
    for (i = 0; i < len; ++i) {
      residual = target - numbers[i];
      if (!mp.count(numbers[i])) {
        mp[residual] = i;
      } else {
        break;
      }
    }
    return vector<int>{mp[numbers[i]] + 1, i + 1};
  }
};


// 4 ms, 9.4 MB. Two pointers.
class Solution2 {
 public:
  vector<int> twoSum(vector<int>& nums, int target) {
    int i = 0;
    int k = nums.size() - 1;
    while (i < k) {
      int sum2 = nums[i] + nums[k];
      if (sum2 == target) {
        break;
      } else if (sum2 < target) {
        ++i;
      } else {
        --k;
      }
    }
    return vector<int>{i + 1, k + 1};
  }
};