#include <vector>
#include <unordered_map>
using namespace std;

// 20 ms, 11.2 MB. Use Bucket. O(n)
class Solution {
 public:
  vector<int> topKFrequent(vector<int>& nums, int k) {
    unordered_map<int, int> freq;
    vector<int> ret;

    int max_freq = 1;
    for (const auto& e : nums) {
      if (!freq.count(e)) {
        freq.emplace(e, 1);
      } else {
        freq[e] += 1;
        if (freq[e] > max_freq) {
          max_freq = freq[e];
        }
      }
    }

    vector<int> bucket[max_freq + 1];
    for (const auto& iter : freq) {
      bucket[iter.second].emplace_back(iter.first);
    }

    for (int i = max_freq, cnt = 1; i >= 0 && cnt <= k; --i) {
      if (!bucket[i].empty()) {
        for (const int& e : bucket[i]) {
          ret.emplace_back(e);
          ++cnt;
        }
      }
    }
    return ret;
  }
};