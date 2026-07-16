// @leetcode id=2181 questionId=2299 slug=merge-nodes-in-between-zeros lang=cpp site=leetcode.com title="Merge Nodes in Between Zeros"
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
    ListNode* mergeNodes(ListNode* head) {
        ListNode* dummy = new ListNode(0);
        ListNode* tail = dummy;
        ListNode* cur = head->next;
        int sum = 0;
        while (cur) {
            if (cur->val == 0) {
                tail->next = new ListNode(sum);
                tail = tail->next;
                sum = 0;
            } else {
                sum += cur->val;
            }
            cur = cur->next;
        }
        return dummy->next;
    }
};
