// @leetcode id=160 questionId=160 slug=intersection-of-two-linked-lists lang=cpp site=leetcode.com title="Intersection of Two Linked Lists"
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        if (!headA || !headB) return nullptr;
        ListNode* a = headA;
        ListNode* b = headB;
        // Each pointer walks its own list then the other's; both traverse
        // the same total length (lenA+lenB), so they meet exactly at the
        // intersection (or both hit null together if there is none).
        while (a != b) {
            a = a ? a->next : headB;
            b = b ? b->next : headA;
        }
        return a;
    }
};
