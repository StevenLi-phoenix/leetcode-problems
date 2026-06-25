// @leetcode id=61 questionId=61 slug=rotate-list lang=cpp site=leetcode.com title="Rotate List"
class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        if (!head || !head->next || k == 0) return head;
        
        // Find the length and tail
        int len = 1;
        ListNode* tail = head;
        while (tail->next) {
            tail = tail->next;
            len++;
        }
        
        // Effective rotation
        k = k % len;
        if (k == 0) return head;
        
        // Find new tail: (len - k - 1) steps from head
        ListNode* newTail = head;
        for (int i = 0; i < len - k - 1; i++) {
            newTail = newTail->next;
        }
        
        ListNode* newHead = newTail->next;
        newTail->next = nullptr;
        tail->next = head;
        
        return newHead;
    }
};
