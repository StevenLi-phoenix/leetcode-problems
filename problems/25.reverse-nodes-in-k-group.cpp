// @leetcode id=25 questionId=25 slug=reverse-nodes-in-k-group lang=cpp site=leetcode.com title="Reverse Nodes in k-Group"
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
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* node = head;
        for (int i = 0; i < k; ++i) {
            if (!node) return head; // fewer than k nodes remain, leave as is
            node = node->next;
        }

        // node now points to the start of the next group
        ListNode* newHead = reverseKGroup(node, k);

        ListNode* prev = newHead;
        ListNode* cur = head;
        for (int i = 0; i < k; ++i) {
            ListNode* nxt = cur->next;
            cur->next = prev;
            prev = cur;
            cur = nxt;
        }
        return prev;
    }
};
