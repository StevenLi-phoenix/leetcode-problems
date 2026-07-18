// @leetcode id=1463 questionId=1559 slug=cherry-pickup-ii lang=cpp site=leetcode.com title="Cherry Pickup II"
class Solution {
public:
    int cherryPickup(vector<vector<int>>& grid) {
        int rows = grid.size(), cols = grid[0].size();
        vector<vector<int>> dp(cols, vector<int>(cols, -1));
        dp[0][cols - 1] = grid[0][0] + (cols == 1 ? 0 : grid[0][cols - 1]);

        for (int r = 1; r < rows; r++) {
            vector<vector<int>> ndp(cols, vector<int>(cols, -1));
            for (int c1 = 0; c1 < cols; c1++) {
                for (int c2 = 0; c2 < cols; c2++) {
                    if (dp[c1][c2] < 0) continue;
                    for (int d1 = -1; d1 <= 1; d1++) {
                        int nc1 = c1 + d1;
                        if (nc1 < 0 || nc1 >= cols) continue;
                        for (int d2 = -1; d2 <= 1; d2++) {
                            int nc2 = c2 + d2;
                            if (nc2 < 0 || nc2 >= cols) continue;
                            int gain = grid[r][nc1];
                            if (nc1 != nc2) gain += grid[r][nc2];
                            int val = dp[c1][c2] + gain;
                            ndp[nc1][nc2] = max(ndp[nc1][nc2], val);
                        }
                    }
                }
            }
            dp = ndp;
        }

        int best = 0;
        for (int c1 = 0; c1 < cols; c1++)
            for (int c2 = 0; c2 < cols; c2++)
                best = max(best, dp[c1][c2]);

        return best;
    }
};
