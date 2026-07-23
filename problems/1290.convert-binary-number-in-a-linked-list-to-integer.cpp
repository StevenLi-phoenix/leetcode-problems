// @leetcode id=1290 questionId=1411 slug=convert-binary-number-in-a-linked-list-to-integer lang=cpp site=leetcode.com title="Convert Binary Number in a Linked List to Integer"
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
    int getDecimalValue(ListNode* head) {
        int result = 0;
        for (ListNode* node = head; node != nullptr; node = node->next) {
            result = result * 2 + node->val;
        }
        return result;
    }
};
