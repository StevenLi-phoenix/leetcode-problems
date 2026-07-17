// @leetcode id=3276 questionId=3563 slug=select-cells-in-grid-with-maximum-score lang=cpp site=leetcode.com title="Select Cells in Grid With Maximum Score"
class Solution {
public:
    int maxScore(vector<vector<int>>& grid) {
        int m = grid.size();
        unordered_map<int,int> rowMaskForValue;

        for (int r = 0; r < m; r++) {
            for (int v : grid[r]) {
                rowMaskForValue[v] |= (1 << r);
            }
        }

        int full = 1 << m;
        vector<int> dp(full, 0);

        for (auto& [v, rowMask] : rowMaskForValue) {
            vector<int> newDp = dp;
            for (int mask = 0; mask < full; mask++) {
                if (dp[mask] < 0) continue;
                for (int r = 0; r < m; r++) {
                    if (!(rowMask & (1 << r))) continue;
                    if (mask & (1 << r)) continue;
                    int newMask = mask | (1 << r);
                    newDp[newMask] = max(newDp[newMask], dp[mask] + v);
                }
            }
            dp = newDp;
        }

        int answer = 0;
        for (int mask = 0; mask < full; mask++) answer = max(answer, dp[mask]);

        return answer;
    }
};
