// 4 ms, 8.6 MB. Use a fake head.
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if (!head) return head;
        
        ListNode* fakeHead = new ListNode(0);
        fakeHead->next = head;
        ListNode* beforeFirst = fakeHead;
        ListNode* first = head;
        ListNode* second = head;
        for (int i = 0; i < n; ++i)
            second = second->next;
        
        while (second != NULL) {
            beforeFirst = beforeFirst->next;
            first = first->next;
            second = second->next;
        }
        beforeFirst->next = first->next;
        delete first;
        return fakeHead->next;
    }
};