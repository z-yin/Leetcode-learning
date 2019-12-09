#include <queue>
#include <stack>
#include <vector>
using namespace std;

struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

// 4 ms	13.7 MB. One queue and two stacks.
class Solution {
 public:
  vector<vector<int>> zigzagLevelOrder(TreeNode *root) {
    vector<vector<int>> res;
    if (!root) return res;

    queue<TreeNode *> q;
    stack<TreeNode *> s1, s2;
    q.emplace(root);

    while (!q.empty() || !s1.empty()) {
      vector<int> vec;
      while (!q.empty()) {
        TreeNode *t = q.front();
        q.pop();
        vec.emplace_back(t->val);
        if (t->left) s1.emplace(t->left);
        if (t->right) s1.emplace(t->right);
      }
      if (!vec.empty()) res.emplace_back(vec);

      vec.clear();
      while (!s1.empty()) {
        TreeNode *t = s1.top();
        s1.pop();
        vec.emplace_back(t->val);
        s2.emplace(t);
      }
      if (!vec.empty()) res.emplace_back(vec);

      while (!s2.empty()) {
        TreeNode *t = s2.top();
        s2.pop();
        if (t->left) q.emplace(t->left);
        if (t->right) q.emplace(t->right);
      }
    }
    return res;
  }
};