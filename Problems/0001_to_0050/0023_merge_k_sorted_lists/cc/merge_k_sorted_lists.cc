#include <vector>
using namespace std;

struct ListNode {
  int val;
  ListNode *next;
  ListNode(int x) : val(x), next(NULL) {}
};

// 24 ms, 11 MB. Divide and conquer.
class Solution {
 public:
  ListNode *mergeKLists(vector<ListNode *> &lists) {
    if (lists.empty()) {
      return nullptr;
    }
    return mergeKLists(lists, 0, lists.size() - 1);
  }

 private:
  ListNode *mergeKLists(const vector<ListNode *> &lists, int start, int end) {
    if (end == start) {
      return lists[start];
    }
    if (end - start == 1) {
      return mergeTwoLists(lists[start], lists[end]);
    }
    int mid = (start + end) / 2;
    ListNode *l1 = mergeKLists(lists, start, mid);
    ListNode *l2 = mergeKLists(lists, mid + 1, end);
    return mergeTwoLists(l1, l2);
  }

  ListNode *mergeTwoLists(ListNode *l1, ListNode *l2) {
    if (!l1 || !l2) {
      return l1 ? l1 : l2;
    }
    ListNode *ret;
    ListNode *h;
    if (l1->val <= l2->val) {
      h = l1;
      l1 = l1->next;
    } else {
      h = l2;
      l2 = l2->next;
    }
    ret = h;
    while (l1 && l2) {
      if (l1->val <= l2->val) {
        h->next = l1;
        l1 = l1->next;
      } else {
        h->next = l2;
        l2 = l2->next;
      }
      h = h->next;
    }
    if (l1) {
      h->next = l1;
    } else if (l2) {
      h->next = l2;
    }
    return ret;
  }
};