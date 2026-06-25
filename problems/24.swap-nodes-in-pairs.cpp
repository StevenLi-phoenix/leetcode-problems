// @leetcode id=24 questionId=24 slug=swap-nodes-in-pairs lang=cpp site=leetcode.com title="Swap Nodes in Pairs"
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
    ListNode* swapPairs(ListNode* head) {
        // Create dummy node to simplify edge cases
        ListNode* dummy = new ListNode(0);
        dummy->next = head;
        
        ListNode* prev = dummy;
        
        while (prev->next != nullptr && prev->next->next != nullptr) {
            // Nodes to be swapped
            ListNode* first = prev->next;
            ListNode* second = prev->next->next;
            
            // Swap
            prev->next = second;
            first->next = second->next;
            second->next = first;
            
            // Move to next pair
            prev = first;
        }
        
        return dummy->next;
    }
};
