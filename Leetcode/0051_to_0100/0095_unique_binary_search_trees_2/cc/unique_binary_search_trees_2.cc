#include <vector>
using namespace std;

// 12 ms, 17.2 MB. DP
struct TreeNode {
  int val;
  TreeNode* left;
  TreeNode* right;
  TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
 public:
  vector<TreeNode*> generateTrees(int n) {
    return n > 0 ? GenerateSubTrees(1, n) : vector<TreeNode*>();
  }

 private:
  vector<TreeNode*> GenerateSubTrees(const int& start, const int& end) {
    vector<TreeNode*> tree_list;
    if (start > end) {
      tree_list.emplace_back(nullptr);
      return tree_list;
    }
    for (int i = start; i <= end; ++i) {
      vector<TreeNode*> left_trees = GenerateSubTrees(start, i - 1);
      vector<TreeNode*> right_trees = GenerateSubTrees(i + 1, end);

      for (auto left : left_trees) {
        for (auto right : right_trees) {
          TreeNode* root = new TreeNode(i);
          root->left = left;
          root->right = right;
          tree_list.emplace_back(root);
        }
      }
    }
    return tree_list;
  }
};