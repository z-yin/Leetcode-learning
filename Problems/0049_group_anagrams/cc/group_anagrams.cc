#include <string>
#include <unordered_map>
#include <vector>
using namespace std;

// 28 ms, 17.6 MB. Hashmap and.
class Solution {
 public:
  vector<vector<string>> groupAnagrams(vector<string>& strs) {
    vector<vector<string>> ret;
    unordered_map<string, int> index;
    for (auto& s : strs) {
      string tmp = s;
      sort(tmp.begin(), tmp.end());
      if (index.count(tmp)) {
        ret[index[tmp]].emplace_back(s);
      } else {
        index[tmp] = ret.size();
        ret.emplace_back(vector<string>{s});
      }
    }
    return ret;
  }
};
