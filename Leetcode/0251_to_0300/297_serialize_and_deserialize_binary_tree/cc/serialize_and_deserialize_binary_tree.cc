#include <string>
#include <stack>
using namespace std;

struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

// 32 ms	26.4 MB
class Codec {
 public:
  // Encodes a tree to a single string.
  string serialize(TreeNode *r) {
    string res;
    stack<TreeNode *> s;
    s.push(r);
    while (!s.empty()) {
      TreeNode *t = s.top();
      s.pop();
      res.append(t ? to_string(t->val) + "!" : "#");
      if (t) {
        s.push(t->right);
        s.push(t->left);
      }
    }
    return res;
  }

  // Decodes your encoded data to tree.
  TreeNode *deserialize(string s) {
    int start = 0;
    return help(s, start);
  }

  TreeNode *help(const string &s, int &start) {
    if (s[start] == '#') return nullptr;
    string n;
    while (s[start] != '!') n += s[start++];
    TreeNode *r = new TreeNode(stoi(n));
    r->left = help(s, ++start);
    r->right = help(s, ++start);
    return r;
  }
};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.deserialize(codec.serialize(root));