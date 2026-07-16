// @leetcode id=86 questionId=86 slug=partition-list lang=cpp site=leetcode.com title="Partition List"
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
    ListNode* partition(ListNode* head, int x) {
        ListNode lessDummy(0), geDummy(0);
        ListNode* lessTail = &lessDummy;
        ListNode* geTail = &geDummy;

        for (ListNode* cur = head; cur; cur = cur->next) {
            if (cur->val < x) {
                lessTail->next = cur;
                lessTail = cur;
            } else {
                geTail->next = cur;
                geTail = cur;
            }
        }
        geTail->next = nullptr;
        lessTail->next = geDummy.next;
        return lessDummy.next;
    }
};
