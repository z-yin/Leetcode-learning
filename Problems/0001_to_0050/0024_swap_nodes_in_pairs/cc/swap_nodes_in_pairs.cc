struct ListNode {
  int val;
  ListNode *next;
  ListNode(int x) : val(x), next(nullptr) {}
};

// 4 ms, 8.5 MB. Two pointers.
class Solution1 {
 public:
  ListNode *swapPairs(ListNode *head) {
    if (!head || !head->next) {
      return head;
    }
    ListNode *first = head;
    ListNode *second = head->next;
    ListNode *prev = new ListNode(0);
    ListNode *dummy = prev;
    while (second) {
      prev->next = second;
      first->next = second->next;
      second->next = first;
      prev = first;
      first = first->next;
      if (!first) {
        break;
      }
      second = first->next;
    }
    return dummy->next;
  }
};

// 0 ms, 8.7 MB. Single pointer.
class Solution {
 public:
  ListNode *swapPairs(ListNode *head) {
    ListNode *dummy = new ListNode(0);
    ListNode *curr = dummy;
    dummy->next = head;
    while (curr->next && curr->next->next) {
      ListNode *tmp = curr->next;
      curr->next = curr->next->next;
      tmp->next = curr->next->next;
      curr->next->next = tmp;
      curr = tmp;
    }
    return dummy->next;
  }
};
