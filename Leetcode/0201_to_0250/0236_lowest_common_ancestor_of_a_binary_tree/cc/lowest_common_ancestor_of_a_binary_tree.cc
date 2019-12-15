struct TreeNode {
  int val;
  TreeNode* left;
  TreeNode* right;
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

// 20 ms	16.7 MB. DFS.
class Solution {
 public:
  TreeNode* lowestCommonAncestor(TreeNode* r, TreeNode* p, TreeNode* q) {
    if (!r) return nullptr;
    if (r == p || r == q) return r;
    TreeNode* left = lowestCommonAncestor(r->left, p, q);
    TreeNode* right = lowestCommonAncestor(r->right, p, q);
    if (left && right) return r;
    if (left) return left;
    if (right) return right;
    return nullptr;
  }
};
