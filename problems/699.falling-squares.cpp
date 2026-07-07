// @leetcode id=699 questionId=699 slug=falling-squares lang=cpp site=leetcode.com title="Falling Squares"
class Solution {
public:
    vector<int> fallingSquares(vector<vector<int>>& positions) {
        int n = positions.size();
        vector<int> top(n, 0); // top height of square i's own stack after landing
        vector<int> ans(n);
        int overallMax = 0;

        for (int i = 0; i < n; ++i) {
            long long left = positions[i][0];
            long long side = positions[i][1];
            long long right = left + side;

            int base = 0;
            for (int j = 0; j < i; ++j) {
                long long jLeft = positions[j][0];
                long long jRight = jLeft + positions[j][1];
                if (left < jRight && jLeft < right) {
                    base = max(base, top[j]);
                }
            }

            top[i] = base + (int)side;
            overallMax = max(overallMax, top[i]);
            ans[i] = overallMax;
        }
        return ans;
    }
};
