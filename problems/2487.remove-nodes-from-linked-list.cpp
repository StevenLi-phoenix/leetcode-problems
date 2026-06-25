// @leetcode id=2487 questionId=2573 slug=remove-nodes-from-linked-list lang=cpp site=leetcode.com title="Remove Nodes From Linked List"
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
    ListNode* removeNodes(ListNode* head) {
        if (!head) return nullptr;

        head->next = removeNodes(head->next);

        if (head->next && head->val < head->next->val) {
            return head->next;
        }

        return head;
    }
};
