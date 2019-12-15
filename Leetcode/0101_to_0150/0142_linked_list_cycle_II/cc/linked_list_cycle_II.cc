struct ListNode {
  int val;
  ListNode *next;
  ListNode(int x) : val(x), next(nullptr) {}
};

// 	12 ms	9.6 MB. Floyd's Tortoise and Hare.
class Solution {
 public:
  ListNode *detectCycle(ListNode *h) {
    if (!h) return nullptr;

    ListNode *slow = h, *fast = h;
    while (fast) {
      slow = slow->next;
      fast = fast->next ? fast->next->next : nullptr;
      if (slow == fast) break;
    }

    if (!fast) return nullptr;

    slow = h;
    while (slow != fast) slow = slow->next, fast = fast->next;

    return slow;
  }
};