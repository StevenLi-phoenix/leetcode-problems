// @leetcode id=1171 questionId=1267 slug=remove-zero-sum-consecutive-nodes-from-linked-list lang=cpp site=leetcode.com title="Remove Zero Sum Consecutive Nodes from Linked List"
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
    ListNode* removeZeroSumSublists(ListNode* head) {
        ListNode dummy(0);
        dummy.next = head;

        unordered_map<int, ListNode*> lastNodeWithSum;
        int sum = 0;
        lastNodeWithSum[0] = &dummy;
        for (ListNode* node = head; node; node = node->next) {
            sum += node->val;
            lastNodeWithSum[sum] = node;
        }

        sum = 0;
        for (ListNode* node = &dummy; node; node = node->next) {
            sum += (node == &dummy) ? 0 : node->val;
            node->next = lastNodeWithSum[sum]->next;
        }
        return dummy.next;
    }
};
