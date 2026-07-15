// @leetcode id=2816 questionId=2871 slug=double-a-number-represented-as-a-linked-list lang=cpp site=leetcode.com title="Double a Number Represented as a Linked List"
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
    ListNode* doubleIt(ListNode* head) {
        vector<int> digits;
        for (ListNode* cur = head; cur; cur = cur->next) digits.push_back(cur->val);

        int carry = 0;
        for (int i = (int)digits.size() - 1; i >= 0; i--) {
            int v = digits[i] * 2 + carry;
            digits[i] = v % 10;
            carry = v / 10;
        }

        ListNode* newHead = head;
        if (carry) {
            newHead = new ListNode(carry, head);
        }

        ListNode* cur = newHead;
        if (carry) cur = cur->next;
        for (int d : digits) {
            cur->val = d;
            cur = cur->next;
        }
        return newHead;
    }
};
