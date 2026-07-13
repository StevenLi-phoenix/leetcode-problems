// @leetcode id=3989 questionId=4225 slug=maximum-consistent-columns-in-a-grid lang=cpp site=leetcode.com title="Maximum Consistent Columns in a Grid"
class Solution {
public:
    int maxConsistentColumns(vector<vector<int>>& grid, int limit) {
        int m = grid.size(), n = grid[0].size();
        vector<int> dp(n, 1); // dp[j] = max kept columns ending with column j
        int best = 1;

        for (int j = 0; j < n; j++) {
            for (int i = 0; i < j; i++) {
                bool ok = true;
                for (int r = 0; r < m && ok; r++)
                    if (abs(grid[r][j] - grid[r][i]) > limit) ok = false;
                if (ok) dp[j] = max(dp[j], dp[i] + 1);
            }
            best = max(best, dp[j]);
        }
        return best;
    }
};
