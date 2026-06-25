// @leetcode id=2130 questionId=2236 slug=maximum-twin-sum-of-a-linked-list lang=cpp site=leetcode.com title="Maximum Twin Sum of a Linked List"
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
    int pairSum(ListNode* head) {
        // Step 1: Find middle using slow/fast pointers
        ListNode* slow = head;
        ListNode* fast = head;
        while (fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
        }
        // slow is now at the start of the second half

        // Step 2: Reverse the second half
        ListNode* prev = nullptr;
        ListNode* curr = slow;
        while (curr) {
            ListNode* nxt = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nxt;
        }
        // prev is now the head of the reversed second half

        // Step 3: Walk both halves and find max twin sum
        int maxSum = 0;
        ListNode* p1 = head;
        ListNode* p2 = prev;
        while (p2) {
            maxSum = max(maxSum, p1->val + p2->val);
            p1 = p1->next;
            p2 = p2->next;
        }

        return maxSum;
    }
};
