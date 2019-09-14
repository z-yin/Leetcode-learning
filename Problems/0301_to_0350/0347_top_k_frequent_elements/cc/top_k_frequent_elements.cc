#include <vector>
#include <unordered_map>
using namespace std;

// 20 ms, 11.2 MB. Use Bucket. O(n)
class Solution {
 public:
  vector<int> topKFrequent(vector<int>& nums, int k) {
    unordered_map<int, int> freq;
    vector<int> ret;
    for (const auto& e : nums) ++freq[e];

    vector<vector<int>> bucket(nums.size() + 1);
    for (const auto& iter : freq) {
      bucket[iter.second].emplace_back(iter.first);
    }
    for (int i = bucket.size() - 1; ret.size() < k; --i) {
      for (const int& e : bucket[i]) {
        ret.emplace_back(e);
      }
    }
    return ret;
  }
};