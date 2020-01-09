struct ListNode {
  int val;
  ListNode* next;
  ListNode(int x) : val(x), next(nullptr) {}
};

// 16 ms	9.6 MB.
class Solution {
 public:
  ListNode* oddEvenList(ListNode* h) {
    if (!h || !h->next || !h->next->next) return h;

    ListNode* p1 = h;
    ListNode *even = h->next, *p2 = h->next;
    while (p2->next && p2->next->next) {
      p1->next = p1->next->next;
      p2->next = p2->next->next;
      p1 = p1->next;
      p2 = p2->next;
    }
    if (p1->next->next) {
      p1->next = p1->next->next;
      p1 = p1->next;
    }

    p2->next = nullptr;
    p1->next = even;

    return h;
  }
};