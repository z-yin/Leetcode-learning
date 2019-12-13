#include <queue>
#include <unordered_map>
#include <vector>
using namespace std;

// 20 ms	14 MB. BFS.
class Solution {
 public:
  vector<int> findOrder(int n, vector<vector<int>> &pre) {
    vector<int> res;
    if (n == 0) return res;

    vector<int> in(n, 0);
    for (auto &v : pre) ++in[v[0]];

    queue<int> q;
    for (int i = 0; i < n; ++i)
      if (in[i] == 0) q.emplace(i);

    unordered_map<int, vector<int>> mp;
    for (auto &v : pre) {
      if (mp.count(v[1])) {
        mp[v[1]].emplace_back(v[0]);
      } else {
        mp[v[1]] = vector<int>{v[0]};
      }
    }

    while (!q.empty()) {
      int p = q.front();
      q.pop();
      res.emplace_back(p);
      for (auto &i : mp[p]) {
        --in[i];
        if (in[i] == 0) {
          q.emplace(i);
        }
      }
    }
    if (res.size() != n) res.clear();
    return res;
  }
};