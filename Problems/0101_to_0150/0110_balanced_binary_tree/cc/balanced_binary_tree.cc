#include <algorithm>
using namespace std;

struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

// 12 ms, 17.2 MB. Depth-first search.
class Solution {
 public:
  bool isBalanced(TreeNode *root) {
    depth(root);
    return res;
  }

 private:
  bool res = true;

  int depth(TreeNode *node) {
    if (!node) {
      return 0;
    }
    int left = 0, right = 0;
    if (node->left) {
      left = depth(node->left);
    }
    if (node->right) {
      right = depth(node->right);
    }
    if (abs(left - right) > 1) {
      res = false;
    }
    return 1 + max(left, right);
  }
};