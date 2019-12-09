class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(nullptr), right(nullptr), next(nullptr) {}

    Node(int _val) : val(_val), left(nullptr), right(nullptr), next(nullptr) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};

// 16 ms	19 MB.
class Solution {
 public:
  Node* connect(Node* root) {
    if (!root) return nullptr;
    
    Node* l = root->left;
    Node* r = root->right;
    while (l) {
      l->next = r;
      l = l->right;
      r = r->left;
    }
    connect(root->left);
    connect(root->right);
    return root;
  }
};