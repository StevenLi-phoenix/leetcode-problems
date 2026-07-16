// @leetcode id=147 questionId=147 slug=insertion-sort-list lang=cpp site=leetcode.com title="Insertion Sort List"
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
    ListNode* insertionSortList(ListNode* head) {
        ListNode dummy(0);
        ListNode* cur = head;
        while (cur) {
            ListNode* next = cur->next;
            ListNode* p = &dummy;
            while (p->next && p->next->val <= cur->val) {
                p = p->next;
            }
            cur->next = p->next;
            p->next = cur;
            cur = next;
        }
        return dummy.next;
    }
};
