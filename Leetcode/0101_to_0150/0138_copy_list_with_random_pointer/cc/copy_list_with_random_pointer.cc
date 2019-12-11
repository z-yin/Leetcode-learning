#include <unordered_map>
using namespace std;

class Node {
 public:
  int val;
  Node* next;
  Node* random;

  Node() {}

  Node(int _val, Node* _next, Node* _random) {
    val = _val;
    next = _next;
    random = _random;
  }
};

// 28 ms	22.1 MB. Unordered_map.
class Solution1 {
 public:
  Node* copyRandomList(Node* head) {
    if (!head) return head;

    unordered_map<Node*, Node*> mp;
    Node* h = new Node(head->val, head->next, head->random);
    mp[head] = h;
    Node* t = h;
    while (t->next) {
      Node* next = new Node(t->next->val, t->next->next, t->next->random);
      mp[t->next] = next;
      t->next = next;
      t = next;
    }
    t = h;
    while (t) {
      t->random = mp[head->random];
      t = t->next;
      head = head->next;
    }
    return h;
  }
};

// 32 ms	21.9 MB. O(1).
class Solution2 {
 public:
  Node* copyRandomList(Node* h) {
    if (!h) return nullptr;

    Node* t = h;
    while (t) {
      Node* curr = new Node(t->val, t->next, t->random);
      t->next = curr;
      t = curr->next;
    }
    t = h;
    while (t) {
      if (t->random) t->next->random = t->random->next;
      t = t->next->next;
    }
    Node* nh = h->next;
    t = h;
    while (t->next->next) {
      Node* tn = t->next;
      t->next = tn->next;
      t = t->next;
      tn->next = t->next;
    }
    t->next = nullptr;
    return nh;
  }
};
