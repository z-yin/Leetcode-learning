#include <queue>
#include <unordered_map>
#include <vector>
using namespace std;

// 44 ms	11.9 MB. BFS.
class Solution1 {
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

// 16 ms	14.6 MB. DFS.
class Solution2 {
 public:
  bool canFinish(int n, vector<vector<int>> &pre) {
    if (n == 0) return false;
    if (pre.empty()) return true;

    unordered_map<int, vector<int>> mp;
    for (auto &v : pre) {
      if (mp.count(v[1])) {
        mp[v[1]].emplace_back(v[0]);
      } else {
        mp[v[1]] = vector<int>{v[0]};
      }
    }

    vector<int> visit(n, 0);
    for (int i = 0; i < n; ++i)
      if (!dfs(mp, visit, i)) return false;

    return true;
  }

  bool dfs(unordered_map<int, vector<int>> &mp, vector<int> &v, int i) {
    if (v[i] == -1) return false;
    if (v[i] == 1) return true;

    v[i] = -1;
    if (mp.count(i))
      for (int c : mp[i])
        if (!dfs(mp, v, c)) return false;

    v[i] = 1;
    return true;
  }
};
