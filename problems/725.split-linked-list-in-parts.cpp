// @leetcode id=725 questionId=725 slug=split-linked-list-in-parts lang=cpp site=leetcode.com title="Split Linked List in Parts"
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
    vector<ListNode*> splitListToParts(ListNode* head, int k) {
        int n = 0;
        for (ListNode* cur = head; cur; cur = cur->next) n++;

        int base = n / k, extra = n % k;
        vector<ListNode*> result(k, nullptr);
        ListNode* cur = head;
        for (int i = 0; i < k && cur; i++) {
            result[i] = cur;
            int size = base + (i < extra ? 1 : 0);
            for (int j = 0; j < size - 1; j++) cur = cur->next;
            ListNode* next = cur->next;
            cur->next = nullptr;
            cur = next;
        }
        return result;
    }
};
