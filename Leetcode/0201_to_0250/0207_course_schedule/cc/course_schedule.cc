#include <queue>
#include <vector>
using namespace std;

// bfs
class Solution {
 public:
  bool canFinish(int n, vector<vector<int>> &pre) {
    if (n == 0) return false;
    if (pre.empty()) return true;

    vector<int> in(n, 0);
    for (auto &v : pre) ++in[v[0]];

    queue<int> q;
    for (int i = 0; i < n; ++i)
      if (in[i] == 0) q.emplace(i);

    int num_free = q.size();
    while (!q.empty()) {
      int p = q.front();
      q.pop();
      for (auto &v : pre) {
        if (v[1] == p) {
          --in[v[0]];
          if (in[v[0]] == 0) {
            q.emplace(v[0]);
            ++num_free;
          }
        }
      }
    }
    return num_free == n;
  }
};
