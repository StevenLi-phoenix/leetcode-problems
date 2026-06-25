// @leetcode id=2095 questionId=2216 slug=delete-the-middle-node-of-a-linked-list lang=cpp site=leetcode.com title="Delete the Middle Node of a Linked List"
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
    ListNode* deleteMiddle(ListNode* head) {
        // Edge case: single node -> middle is index 0, delete it -> return nullptr
        if (!head || !head->next) return nullptr;
        
        // Use slow/fast with a prev pointer to find predecessor of middle
        // Middle index = floor(n/2), we need the node at index floor(n/2)-1
        // Trick: start fast one step ahead (head->next->next) so slow lands one before middle
        // Actually simplest: use prev pointer alongside slow/fast
        ListNode* prev = nullptr;
        ListNode* slow = head;
        ListNode* fast = head;
        
        while (fast && fast->next) {
            prev = slow;
            slow = slow->next;
            fast = fast->next->next;
        }
        // slow is now at middle node (index floor(n/2))
        // prev is the node before it
        if (prev) {
            prev->next = slow->next;
        } else {
            // middle is head (n=1 case, already handled above)
            head = head->next;
        }
        
        return head;
    }
};
