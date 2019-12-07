#include <vector>
using namespace std;

// 16 ms	12.3 MB. Sort.
class Solution {
 public:
  vector<vector<int>> merge(vector<vector<int>>& intervals) {
    vector<vector<int>> res;
    if (intervals.empty()) return res;
    sort(intervals.begin(), intervals.end(), [](const vector<int> &a,
                                                const vector<int> &b) {
      return a[0] < b[0];
    });
    
    res.emplace_back(intervals[0]);
    for (int i = 1; i < intervals.size(); ++i) {
      if (intervals[i][0] <= res[res.size() - 1][1]) {
        res[res.size() - 1][1] = max(res[res.size() - 1][1], intervals[i][1]);
      } else {
        res.emplace_back(intervals[i]);
      }
    }
    return res;
  }
};