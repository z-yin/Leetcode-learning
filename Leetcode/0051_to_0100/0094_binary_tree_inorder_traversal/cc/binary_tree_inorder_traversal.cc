#include <stack>
#include <vector>
using namespace std;

struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

// 0 ms	9.1 MB. Stack.
class Solution {
 public:
  vector<int> inorderTraversal(TreeNode *root) {
    stack<TreeNode *> s;
    vector<int> res;
    TreeNode *curr = root;
    while (curr || !s.empty()) {
      while (curr) {
        s.push(curr);
        curr = curr->left;
      }
      curr = s.top();
      res.emplace_back(curr->val);
      s.pop();

      curr = curr->right;
    }
    return res;
  }
};