// @leetcode id=1019 questionId=1072 slug=next-greater-node-in-linked-list lang=cpp site=leetcode.com title="Next Greater Node In Linked List"
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
    vector<int> nextLargerNodes(ListNode* head) {
        vector<int> vals;
        for (ListNode* cur = head; cur; cur = cur->next) vals.push_back(cur->val);

        int n = vals.size();
        vector<int> result(n, 0);
        stack<int> st; // indices with no next-greater found yet
        for (int i = 0; i < n; i++) {
            while (!st.empty() && vals[st.top()] < vals[i]) {
                result[st.top()] = vals[i];
                st.pop();
            }
            st.push(i);
        }
        return result;
    }
};
