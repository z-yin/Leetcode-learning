#include <queue>
#include <vector>
using namespace std;

struct TreeNode {
  int val;
  TreeNode* left;
  TreeNode* right;
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Node {
 public:
  TreeNode* node;
  int level;
  Node(TreeNode* n, int l) : node(n), level(l) {}
};

// 4 ms	13.9 MB. Extra space for storing level.
class Solution {
 public:
  vector<vector<int>> levelOrder(TreeNode* root) {
    vector<vector<int>> res;
    if (!root) return res;
    queue<Node*> q;
    q.emplace(new Node(root, 0));

    int level = 0;
    vector<int> tmp;
    while (!q.empty()) {
      Node* n = q.front();
      q.pop();
      if (n->level != level) {
        res.emplace_back(tmp);
        tmp.clear();
        ++level;
      }
      tmp.emplace_back(n->node->val);
      if (n->node->left) q.emplace(new Node(n->node->left, n->level + 1));
      if (n->node->right) q.emplace(new Node(n->node->right, n->level + 1));
    }
    res.emplace_back(tmp);
    return res;
  }
};