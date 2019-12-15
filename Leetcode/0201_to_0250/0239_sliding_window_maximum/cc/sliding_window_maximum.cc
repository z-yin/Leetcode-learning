#include <vector>
#include <deque>
using namespace std;


// 52 ms	13.1 MB
class Solution {
 public:
  vector<int> maxSlidingWindow(vector<int>& nums, int k) {
    vector<int> res;
    if (nums.empty()) return res;
    deque<int> q;
    q.emplace_back(0);
    int i = 1;
    while (i < k && i < nums.size()) {
      while (!q.empty() && nums[q.back()] <= nums[i])
        q.pop_back();
      q.emplace_back(i);
      ++i;
    }
    res.emplace_back(nums[q.front()]);
    for (; i < nums.size(); ++i) {
      while (!q.empty() && nums[q.back()] <= nums[i])
        q.pop_back();
      q.emplace_back(i);
      while (q.front() < i - k + 1) q.pop_front();
      res.emplace_back(nums[q.front()]);
    }
    return res;
  }
};