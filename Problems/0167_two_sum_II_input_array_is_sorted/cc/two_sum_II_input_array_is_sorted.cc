#include <vector>
#include <unordered_map>
using namespace std;

// 4 ms, 9.6 MB
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