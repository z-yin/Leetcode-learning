#include <cstddef>

struct TreeNode {
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
	TreeNode(int x) :
			val(x), left(NULL), right(NULL) {
	}
};


class Solution {
public:
    bool HasSubtree(TreeNode* pRoot1, TreeNode* pRoot2)
    {
        bool res = false;
        if (!pRoot1 || !pRoot2) return res;
        if (pRoot1->val == pRoot2->val) res = _hasSubtree(pRoot1, pRoot2);
        if (!res) res = _hasSubtree(pRoot1->left, pRoot2);
        if (!res) res = _hasSubtree(pRoot1->right, pRoot2);
        return res;
    }
    
    bool _hasSubtree (TreeNode* r1, TreeNode* r2) {
        if (!r1 && r2) return false;
        if (!r2) return true;
        if (r1->val != r2->val) return false;
        return _hasSubtree(r1->left, r2->left) 
            && _hasSubtree(r1->right, r2->right);
    }
};