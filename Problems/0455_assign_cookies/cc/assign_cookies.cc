#include <vector>
#include <algorithm>
using namespace std;

// 40 ms, 10.3 MB. Greedy.
class Solution {
 public:
  int findContentChildren(vector<int>& g, vector<int>& s) {
    sort(g.begin(), g.end());
    sort(s.begin(), s.end());
    int i = s.size() - 1;
    int k = g.size() - 1;
    int content = 0;
    while (k >= 0 && i >= 0) {
      if (s[i] >= g[k]) {
        ++content;
        --k;
        --i;
      } else {
        --k;
      }
    }
    return content;
  }
};