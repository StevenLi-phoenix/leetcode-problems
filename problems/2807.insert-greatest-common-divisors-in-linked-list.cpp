// @leetcode id=2807 questionId=2903 slug=insert-greatest-common-divisors-in-linked-list lang=cpp site=leetcode.com title="Insert Greatest Common Divisors in Linked List"
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
    ListNode* insertGreatestCommonDivisors(ListNode* head) {
        ListNode* cur = head;
        while (cur && cur->next) {
            int g = gcd(cur->val, cur->next->val);
            ListNode* newNode = new ListNode(g, cur->next);
            cur->next = newNode;
            cur = newNode->next;
        }
        return head;
    }

private:
    int gcd(int a, int b) {
        while (b) { a %= b; swap(a, b); }
        return a;
    }
};
