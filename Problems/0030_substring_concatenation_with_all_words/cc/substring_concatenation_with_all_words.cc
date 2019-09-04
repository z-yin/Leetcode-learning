#include <string>
#include <unordered_map>
#include <vector>
using namespace std;

// 236 ms, 13.9 MB. Two pointers. Unordered_map.
class Solution {
 public:
  vector<int> findSubstring(string s, vector<string> &words) {
    vector<int> ret;
    if (s.empty() || words.empty()) {
      return ret;
    }

    int len_s = s.size();
    int num_words = words.size();
    int len_word = words[0].size();
    unordered_map<string, int> used, backup;
    for (const auto &wd : words) {
      ++backup[wd];
    }
    used = backup;

    int end = len_s - num_words * len_word;
    for (int i = 0; i <= end; ++i) {
      int j = 0;
      while (j < num_words) {
        string substr = s.substr(i + len_word * j, len_word);
        if (used.count(substr) && used[substr] > 0) {
          --used[substr];
          ++j;
        } else {
          break;
        }
      }
      for (auto &pr : used) {
        pr.second = backup[pr.first];
      }
      if (j == num_words) {
        ret.emplace_back(i);
      }
    }
    return ret;
  }
};