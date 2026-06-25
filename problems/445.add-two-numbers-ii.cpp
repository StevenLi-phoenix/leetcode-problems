// @leetcode id=445 questionId=445 slug=add-two-numbers-ii lang=cpp site=leetcode.com title="Add Two Numbers II"
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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        stack<int> s1, s2;

        ListNode* curr = l1;
        while (curr) {
            s1.push(curr->val);
            curr = curr->next;
        }

        curr = l2;
        while (curr) {
            s2.push(curr->val);
            curr = curr->next;
        }

        int carry = 0;
        ListNode* result = nullptr;

        while (!s1.empty() || !s2.empty() || carry) {
            int sum = carry;

            if (!s1.empty()) {
                sum += s1.top();
                s1.pop();
            }

            if (!s2.empty()) {
                sum += s2.top();
                s2.pop();
            }

            carry = sum / 10;
            int digit = sum % 10;

            ListNode* newNode = new ListNode(digit);
            newNode->next = result;
            result = newNode;
        }

        return result;
    }
};
