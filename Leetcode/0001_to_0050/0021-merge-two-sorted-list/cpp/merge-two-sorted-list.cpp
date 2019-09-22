// 4 ms, 9 MB. Not smart.
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution1 {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        if (!l1 || !l2) return l1 ? l1 : l2;
        
        ListNode* fakeHead = new ListNode(0);
        fakeHead->next = l1;
        
        ListNode* l1_first = fakeHead, *l1_second = l1;
        ListNode* l2_first = l2;
        
        while (l1_second && l2_first) {
            if ( l2_first->val < l1_second->val ) {
                ListNode* tmp = l2_first;
                l2_first = l2_first->next;
                l1_first->next = tmp;
                tmp->next = l1_second;
                l1_first = l1_first->next;
            } else {
                l1_first = l1_first->next;
                l1_second = l1_second->next;
            }
        }
        if (l2_first) l1_first->next = l2_first;
        return fakeHead->next;
    }
};

// 4 ms, 9 MB. Use a single ptr to linke two list together
class Solution2 {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        if (!l1 || !l2) return l1 ? l1 : l2;
        ListNode* nh = new ListNode(0), *nhd = nh;
        
        while (l1 && l2) {
            if (l1->val < l2->val) {
                nhd->next = l1;
                l1 = l1->next;
            } else {
                nhd->next = l2;
                l2 = l2->next;
            }
            nhd = nhd->next;
        }
        nhd->next = l1 ? l1 : l2;
        
        return nh->next;
    }
};