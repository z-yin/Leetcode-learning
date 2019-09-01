#include <set>
using namespace std;

struct ListNode {
  int val;
  ListNode *next;
  ListNode(int x) : val(x), next(nullptr) {}
};

// 820 ms, 16.8 MB. Brute-force.
class Solution1 {
 public:
  ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
    ListNode *a = headA;
    ListNode *b = headB;
    while (a) {
      while (b) {
        if (a == b) {
          return a;
        }
        b = b->next;
      }
      b = headB;
      a = a->next;
    }
    return nullptr;
  }
};

// 80 ms, 23.2 MB. Linear time and suits on early intersection.
class Solution2 {
 public:
  ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
    ListNode* a = headA;
    ListNode* b = headB;
    set<ListNode*> node_set;
    while (a && b) {
      if (node_set.count(a))
        return a;
      node_set.emplace(a);
      a = a->next;
      
      if (node_set.count(b))
        return b;
      node_set.emplace(b);
      b = b->next;
    }
    while (a) {
      if (node_set.count(a))
        return a;
      a = a->next;
    }
    while (b) {
      if (node_set.count(b))
        return b;
      b = b->next;
    }
    return nullptr;
  }
};

// 44 ms, 16.8 MB. Using difference of node counts. Don't have to store nodes.
class Solution3 {
 public:
  ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
    ListNode* a = headA;
    ListNode* b = headB;
    int len_a = 0;
    int len_b = 0;
    while (a) {
      ++len_a;
      a = a->next;
    }
    while (b) {
      ++len_b;
      b = b->next;
    }
    ListNode* ret;
    if (len_a >= len_b) {
      ret = getIntersection(headA, headB, len_a, len_b);
    } else {
      ret = getIntersection(headB, headA, len_b, len_a);
    }
    return ret;
  }
  
 private:
  // len of a >= len of b
  ListNode* getIntersection(ListNode* a, ListNode* b, int len_a, int len_b) {
    while (len_a != len_b) {
      --len_a;
      a = a->next;
    }
    while (a /*&& b*/) {
      if (a == b)
        return a;
      a = a->next;
      b = b->next;
    }
    return nullptr;
  }
};