#include <vector>
#include <stack>
#include <iostream>
#include <queue>

struct TreeNode {
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
	TreeNode(int x) :
			val(x), left(NULL), right(NULL) {
	}
};

// Recusive pre-order traversal
void preOrderRecursive (TreeNode* r) {
    if (r) {
        std::cout << r->val << " ";
        preOrderRecursive(r->left);
        preOrderRecursive(r->right);
    }
}

// Recusive in-order traversal
void inOrderRecursive (TreeNode* r) {
    if (r) {
        inOrderRecursive(r->left);
        std::cout << r->val << " ";
        inOrderRecursive(r->right);
    }
}

// Recusive post-order traversal
void postOrderRecursive (TreeNode* r) {
    if (r) {
        postOrderRecursive(r->left);
        postOrderRecursive(r->right);
        std::cout << r->val << " ";
    }
}

// Level order traversal
std::vector<int> levelOrder (TreeNode* r) {
    // Level-order sequence as return variable
    std::vector<int> res;
    if (r) {
        // Create an empty queue for level order tarversal 
        std::queue<TreeNode*> q;
        q.push(r);

        TreeNode* curr;

        while (!q.empty()) {
            curr = q.front();
            q.pop();
            res.emplace_back(curr->val);
            
            /* Enqueue left child */
            if (curr->left) q.emplace(curr->left);
            /* Enqueue left child */
            if (curr->right) q.emplace(curr->right);
        }
    }
    return res;
}

// Iterative pre-order traversal
std::vector<int> preOrderIterative (TreeNode* r) {
    // Pre-order sequence as return variable
    std::vector<int> res;
    if (r) {
        // stack to store the future node that will be accessed
        std::stack<TreeNode*> s;
        s.push(r);
        // current node
        TreeNode* curr = r;

        /* Pop all items one by one. Do following for every popped item 
        a) print it 
        b) push its right child 
        c) push its left child 
        Note that right child is pushed first so that left is processed first */
        while (!s.empty()) {
            // Pop the top item from stack and print it 
            curr = s.top();
            res.emplace_back(curr->val);
            s.pop();
            // Push right and left children of the popped node to stack
            if (curr->right) s.push(curr->right);
            if (curr->left) s.push(curr->left);
        }
    }
    return res;
}

// Iterative in-order traversal
std::vector<int> inOrderIterative (TreeNode* r) {
    // In-order sequence as return variable
    std::vector<int> res;
    if (r) {
        // stack to store the future node that will be accessed
        std::stack<TreeNode*> s;
        // current node
        TreeNode* curr = r;

        // iteratively find the most left node of every "root" node and store the "root"
        while (curr || !s.empty()) {
            // find the most left node of a "root" node and store the "root"
            while (curr) {
                s.push(curr);
                curr = curr->left;
            }
            // most left node should be the parent of the NULL node,
            // which is at the top of the stack
            curr = s.top();
            s.pop();

            // store the most left to the return variable
            res.emplace_back(curr->val);

            // start traversal from the right node of the current node,
            // right node is the next "root" node in the iteration
            curr = curr->right;
        }
    }
    return res;
}

// Iterative in-order traversal
std::vector<int> postOrderIterative (TreeNode* r) {
    // Post-order sequence as return variable
    std::vector<int> res;
    if (r) {
        // stack 1 : helper stack to store the future node that will be accessed
        // stack 2 : to store the post-order sequence
        std::stack<TreeNode*> s1, s2;

        // push the root the stack 1
        s1.push(r);
        TreeNode* node;

        // Run while first stack is not empty 
        while (!s1.empty()) {
            // Pop an item from s1 and push it to s2 
            node = s1.top();
            s1.pop();
            s2.push(node);

            // Push left and right children of removed item to s1 
            if (node->left) s1.push(node->left);
            if (node->right) s1.push(node->right);
        }

        // put values of all elements of second stack to return variable
        while (!s2.empty()) {
            node = s2.top();
            s2.pop();
            res.emplace_back(node->val);
        }
    }
    return res;
}

TreeNode* newNode (int data) {
    TreeNode* node = new TreeNode(data);
    node->left = node->right = NULL;
    return node;
}

// Function to insert nodes in level order
TreeNode* insertLevelOrder(int arr[], TreeNode* root, int i, int n) 
{ 
    // Base case for recursion 
    if (i < n) 
    { 
        TreeNode* temp = newNode(arr[i]);
        root = temp; 
  
        // insert left child 
        root->left = insertLevelOrder(arr, root->left, 2 * i + 1, n); 
  
        // insert right child 
        root->right = insertLevelOrder(arr, root->right, 2 * i + 2, n); 
    }
    return root; 
}