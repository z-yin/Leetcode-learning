struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

class Solution {
 public:
  ListNode* reverseList(ListNode* head) {
    if (!head) return head;
    ListNode* l1 = nullptr;
    ListNode* l2 = head;
    ListNode* l3 = l2->next;
    while (l3) {
      l2->next = l1;
      l1 = l2;
      l2 = l3;
      l3 = l3->next;
    }
    l2->next = l1;
    return l2;
  }
};