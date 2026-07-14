// @leetcode id=2058 questionId=2182 slug=find-the-minimum-and-maximum-number-of-nodes-between-critical-points lang=cpp site=leetcode.com title="Find the Minimum and Maximum Number of Nodes Between Critical Points"
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
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        int idx = 1;
        ListNode* prev = head;
        ListNode* cur = head->next;
        int firstCritical = -1, lastCritical = -1, minDist = INT_MAX;

        while (cur->next) {
            bool isCritical = (cur->val > prev->val && cur->val > cur->next->val) ||
                               (cur->val < prev->val && cur->val < cur->next->val);
            if (isCritical) {
                if (firstCritical == -1) {
                    firstCritical = idx;
                } else {
                    minDist = min(minDist, idx - lastCritical);
                }
                lastCritical = idx;
            }
            prev = cur;
            cur = cur->next;
            idx++;
        }

        if (firstCritical == -1 || firstCritical == lastCritical) return {-1, -1};
        return {minDist, lastCritical - firstCritical};
    }
};
