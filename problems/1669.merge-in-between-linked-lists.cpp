// @leetcode id=1669 questionId=1765 slug=merge-in-between-linked-lists lang=cpp site=leetcode.com title="Merge In Between Linked Lists"
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
    ListNode* mergeInBetween(ListNode* list1, int a, int b, ListNode* list2) {
        ListNode* before = list1;
        for (int i = 0; i < a - 1; i++) before = before->next;

        ListNode* after = before;
        for (int i = 0; i <= b - a + 1; i++) after = after->next;

        before->next = list2;
        ListNode* tail = list2;
        while (tail->next) tail = tail->next;
        tail->next = after;

        return list1;
    }
};
