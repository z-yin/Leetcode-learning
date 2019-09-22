#include <queue>
using namespace std;

// 12 ms, 20.9 MB. Level traverse.
struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

// custom class
struct Node {
  TreeNode *node;
  int level;
  Node(TreeNode *node, int level) : node(node), level(level) {}
};

class Solution {
 public:
  int findBottomLeftValue(TreeNode *root) {
    int res = root->val;
    int curr_level = 1;
    queue<Node> q;
    q.emplace(Node(root, 1));
    // level traverse
    while (!q.empty()) {
      TreeNode *node = q.front().node;
      int level = q.front().level;
      if (level != curr_level) {
        res = node->val;
        curr_level = level;
      }
      if (node->left) q.emplace(Node(node->left, level + 1));
      if (node->right) q.emplace(Node(node->right, level + 1));
      q.pop();
    }
    return res;
  }
};