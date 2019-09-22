struct ListNode {
  int val;
  ListNode *next;
  ListNode(int x) : val(x), next(nullptr) {}
};

// 20 ms, 9.7 MB.
class Solution {
 public:
  ListNode *reverseKGroup(ListNode *head, int k) {
    if (!head || !head->next || k == 1) {
      return head;
    }
    ListNode dummy(0);
    dummy.next = head;
    ListNode *prev = &dummy;
    ListNode *curr = head;
    int cnt = 0;
    while (curr) {
      ++cnt;
      if (cnt % k == 0) {
        ListNode *new_prev;
        prev = reverse(prev, curr->next, new_prev);
        curr = prev->next;
      } else {
        curr = curr->next;
      }
    }
    return dummy.next;
  }

 private:
  ListNode *reverse(ListNode *prev, ListNode *next, ListNode *tail) {
    ListNode *p = prev->next;
    ListNode *q = p->next;
    while (q != next) {
      ListNode *t = q->next;
      q->next = p;
      p = q;
      q = t;
    }
    tail = prev->next;
    prev->next->next = next;
    prev->next = p;
    return tail;
  }
};