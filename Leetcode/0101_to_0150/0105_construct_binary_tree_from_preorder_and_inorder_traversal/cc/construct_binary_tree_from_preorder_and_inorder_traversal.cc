#include <unordered_map>
#include <vector>
using namespace std;

struct TreeNode {
  int val;
  TreeNode* left;
  TreeNode* right;
  TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

// 12 ms	17 MB. DFS and map.
class Solution {
 public:
  unordered_map<int, int> mp;
  int curr_idx;

  TreeNode* buildTree(vector<int>& pre, vector<int>& in) {
    for (int i = 0; i < in.size(); ++i) mp[in[i]] = i;
    curr_idx = 0;
    return dfs(0, pre.size(), pre);
  }

  TreeNode* dfs(int l, int r, vector<int>& pre) {
    if (l == r) return nullptr;
    TreeNode* t = new TreeNode(pre[curr_idx]);
    int idx = mp[pre[curr_idx++]];
    t->left = dfs(l, idx, pre);
    t->right = dfs(idx + 1, r, pre);
    return t;
  }
};