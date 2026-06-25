// @leetcode id=19 questionId=19 slug=remove-nth-node-from-end-of-list lang=cpp site=leetcode.com title="Remove Nth Node From End of List"
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        // Create a dummy node pointing to head
        ListNode* dummy = new ListNode(0);
        dummy->next = head;
        
        // First pass: count the total number of nodes
        int length = 0;
        ListNode* current = head;
        while (current) {
            length++;
            current = current->next;
        }
        
        // Calculate position from start (not from end)
        int pos = length - n;
        
        // Second pass: find the node before the one to remove
        current = dummy;
        for (int i = 0; i < pos; i++) {
            current = current->next;
        }
        
        // Remove the node
        current->next = current->next->next;
        
        ListNode* result = dummy->next;
        delete dummy;
        return result;
    }
};
