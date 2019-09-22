#include <stack>
using namespace std;

struct TreeNode {
  int val;
  TreeNode* left;
  TreeNode* right;
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

// 20 ms, 21.6 MB. Inorder traversal. Using stack.
class Solution1 {
 public:
  int kthSmallest(TreeNode* root, int k) {
    int res;
    stack<TreeNode*> s;
    TreeNode* curr = root;
    while (curr || !s.empty()) {
      while (curr) {
        s.emplace(curr);
        curr = curr->left;
      }
      curr = s.top();
      s.pop();
      res = curr->val;
      if (--k == 0) break;
      curr = curr->right;
    }
    return res;
  }
};

// 32 ms, 24.1 MB. Divede and conquer.
// Build another tree with count of elments.
// Optimization for finding the kth smallest of BST which is
// modified (insert/delete operations) frequently.
struct Node {
  TreeNode* node;
  Node* left;
  Node* right;
  int count;
  Node(TreeNode* node, Node* left = nullptr, Node* right = nullptr,
       int count = 0)
      : node(node), left(left), right(right), count(count) {}
};

class Solution2 {
 public:
  int kthSmallest(TreeNode* root, int k) {
    int res;
    Node* rt = new Node(root);
    build(rt);
    int base = 0;
    while (rt) {
      int left = rt->left ? rt->left->count : 0;
      int right = rt->right ? rt->right->count : 0;
      if (base + left + 1 == k) {
        res = rt->node->val;
        break;
      }
      if (base + left >= k) {
        rt = rt->left;
      } else {
        base += rt->count - rt->right->count;
        rt = rt->right;
      }
    }
    return res;
  }

 private:
  int build(Node* m_node) {
    if (!m_node) return 0;
    m_node->left = m_node->node->left ? new Node(m_node->node->left) : nullptr;
    m_node->right =
        m_node->node->right ? new Node(m_node->node->right) : nullptr;
    m_node->count = build(m_node->left) + build(m_node->right) + 1;
    return m_node->count;
  }
};