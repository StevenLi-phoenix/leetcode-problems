// @leetcode id=21 questionId=21 slug=merge-two-sorted-lists lang=cpp site=leetcode.com title="Merge Two Sorted Lists"
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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        // Create a dummy node to simplify the merge process
        ListNode* dummy = new ListNode(0);
        ListNode* current = dummy;
        
        // Traverse both lists and merge them
        while (list1 && list2) {
            if (list1->val <= list2->val) {
                current->next = list1;
                list1 = list1->next;
            } else {
                current->next = list2;
                list2 = list2->next;
            }
            current = current->next;
        }
        
        // Attach the remaining nodes from either list
        if (list1) {
            current->next = list1;
        } else {
            current->next = list2;
        }
        
        ListNode* result = dummy->next;
        delete dummy;
        return result;
    }
};
