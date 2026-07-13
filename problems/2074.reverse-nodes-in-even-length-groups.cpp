// @leetcode id=2074 questionId=2196 slug=reverse-nodes-in-even-length-groups lang=cpp site=leetcode.com title="Reverse Nodes in Even Length Groups"
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
    ListNode* reverseEvenLengthGroups(ListNode* head) {
        ListNode* prevTail = head;
        int groupSize = 2;
        ListNode* cur = head->next;

        while (cur) {
            vector<ListNode*> nodes;
            ListNode* p = cur;
            for (int i = 0; i < groupSize && p; i++) {
                nodes.push_back(p);
                p = p->next;
            }

            int actual = nodes.size();
            if (actual % 2 == 0) {
                for (int i = actual - 1; i > 0; i--) nodes[i]->next = nodes[i - 1];
                prevTail->next = nodes[actual - 1];
                nodes[0]->next = p;
                prevTail = nodes[0];
            } else {
                prevTail = nodes[actual - 1];
            }

            cur = p;
            groupSize++;
        }
        return head;
    }
};
