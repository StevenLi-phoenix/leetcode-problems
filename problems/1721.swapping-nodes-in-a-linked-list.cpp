// @leetcode id=1721 questionId=528 slug=swapping-nodes-in-a-linked-list lang=cpp site=leetcode.com title="Swapping Nodes in a Linked List"
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
    ListNode* swapNodes(ListNode* head, int k) {
        ListNode* first = head;
        for (int i = 1; i < k; i++) first = first->next;

        ListNode* second = head;
        ListNode* runner = first;
        while (runner->next) {
            runner = runner->next;
            second = second->next;
        }

        swap(first->val, second->val);
        return head;
    }
};
