#include <stack>
#include <vector>
using namespace std;

// 0 ms, 9.1 MB. Preorder traverse. Using stack.
struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
 public:
  vector<int> preorderTraversal(TreeNode *root) {
    vector<int> res;
    if (!root) return res;
    stack<TreeNode *> s;
    s.emplace(root);
    // preorder traversal
    while (!s.empty()) {
      TreeNode *tmp = s.top();
      s.pop();
      res.emplace_back(tmp->val);
      if (tmp->right) s.emplace(tmp->right);
      if (tmp->left) s.emplace(tmp->left);
    }
    return res;
  }
};