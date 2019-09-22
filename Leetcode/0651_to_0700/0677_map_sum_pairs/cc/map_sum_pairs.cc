#include <string>
#include <unordered_map>
using namespace std;

// 4 ms, 9.7 MB. Trie.
class MapSum {
 public:
  /** Initialize your data structure here. */
  MapSum() { root = new Node(); }

  ~MapSum() { delete root; }

  void insert(string key, int val) {
    Node *curr = root;
    for (const auto &c : key) {
      if (!curr->nodes_.count(c)) {
        (curr->nodes_)[c] = new Node();
      }
      curr = (curr->nodes_)[c];
    }
    curr->val_ = val;
  }

  int sum(string prefix) {
    Node *curr = root;
    for (const auto &c : prefix) {
      if (!curr->nodes_.count(c)) return 0;
      curr = (curr->nodes_)[c];
    }
    return sum(curr);
  }

 private:
  class Node {
   public:
    int val_;
    unordered_map<char, Node *> nodes_;
    Node(int val = 0) : val_(val) {}
  };

  Node *root;

  int sum(Node *node) {
    int res = node->val_;
    for (const auto &pair : node->nodes_) {
      res += sum(pair.second);
    }
    return res;
  }
};

/**
 * Your MapSum object will be instantiated and called as such:
 * MapSum* obj = new MapSum();
 * obj->insert(key,val);
 * int param_2 = obj->sum(prefix);
 */