// @leetcode id=2326 questionId=2411 slug=spiral-matrix-iv lang=cpp site=leetcode.com title="Spiral Matrix IV"
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
    vector<vector<int>> spiralMatrix(int m, int n, ListNode* head) {
        vector<vector<int>> matrix(m, vector<int>(n, -1));
        int top = 0, bottom = m - 1, left = 0, right = n - 1;
        ListNode* cur = head;

        auto next = [&]() -> int {
            if (!cur) return -1;
            int v = cur->val;
            cur = cur->next;
            return v;
        };

        while (top <= bottom && left <= right && cur) {
            for (int c = left; c <= right && cur; ++c) matrix[top][c] = next();
            ++top;
            for (int r = top; r <= bottom && cur; ++r) matrix[r][right] = next();
            --right;
            for (int c = right; c >= left && cur; --c) matrix[bottom][c] = next();
            --bottom;
            for (int r = bottom; r >= top && cur; --r) matrix[r][left] = next();
            ++left;
        }
        return matrix;
    }
};
