#include <climits>
using namespace std;

struct TreeNode {
  int val;
  TreeNode* left;
  TreeNode* right;
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

// 20 ms	20.4 MB. Left and right bound.
class Solution {
 public:
  bool isValidBST(TreeNode* root) {
    return help(root, INT_MIN - 1.0, INT_MAX + 1.0);
  }

  bool help(TreeNode* root, double l, double r) {
    if (!root) return true;
    if (root->val <= l || root->val >= r) return false;
    return help(root->left, l, root->val) && help(root->right, root->val, r);
  }
};