// @leetcode id=82 questionId=82 slug=remove-duplicates-from-sorted-list-ii lang=cpp site=leetcode.com title="Remove Duplicates from Sorted List II"
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
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode dummy(0, head);
        ListNode* prev = &dummy;
        ListNode* cur = head;
        while (cur) {
            if (cur->next && cur->next->val == cur->val) {
                int dupVal = cur->val;
                while (cur && cur->val == dupVal) cur = cur->next;
                prev->next = cur;
            } else {
                prev = cur;
                cur = cur->next;
            }
        }
        return dummy.next;
    }
};
