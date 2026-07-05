// @leetcode id=741 questionId=741 slug=cherry-pickup lang=cpp site=leetcode.com title="Cherry Pickup"
class Solution {
public:
    int cherryPickup(vector<vector<int>>& grid) {
        int n = grid.size();
        const int NEG = INT_MIN / 2;
        int maxStep = 2 * n - 2;

        vector<vector<vector<int>>> dp(maxStep + 1, vector<vector<int>>(n, vector<int>(n, NEG)));
        dp[0][0][0] = grid[0][0];

        for (int step = 1; step <= maxStep; ++step) {
            int xLo = max(0, step - (n - 1)), xHi = min(n - 1, step);
            for (int x1 = xLo; x1 <= xHi; ++x1) {
                int y1 = step - x1;
                if (grid[x1][y1] == -1) continue;
                for (int x2 = xLo; x2 <= xHi; ++x2) {
                    int y2 = step - x2;
                    if (grid[x2][y2] == -1) continue;

                    int best = NEG;
                    for (int dx1 = 0; dx1 <= 1; ++dx1) {
                        int px1 = x1 - dx1;
                        if (px1 < 0) continue;
                        for (int dx2 = 0; dx2 <= 1; ++dx2) {
                            int px2 = x2 - dx2;
                            if (px2 < 0) continue;
                            best = max(best, dp[step - 1][px1][px2]);
                        }
                    }
                    if (best == NEG) continue;

                    int gain = grid[x1][y1] + (x1 != x2 ? grid[x2][y2] : 0);
                    dp[step][x1][x2] = best + gain;
                }
            }
        }

        return max(0, dp[maxStep][n - 1][n - 1]);
    }
};
