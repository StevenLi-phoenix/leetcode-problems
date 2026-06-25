// @leetcode id=3742 questionId=3986 slug=maximum-path-score-in-a-grid lang=cpp site=leetcode.com title="Maximum Path Score in a Grid"
class Solution {
public:
    int maxPathScore(vector<vector<int>>& grid, int k) {
        int m = grid.size(), n = grid[0].size();
        // dp[i][j][c] = max score at cell (i,j) with exactly c cost used
        // cost: cell value 0 costs 0, cell value 1 costs 1, cell value 2 costs 1
        // score: cell value 0 scores 0, cell value 1 scores 1, cell value 2 scores 2
        // path length = m+n-1 cells, max cost = m+n-1
        int maxCost = m + n - 1;
        if (k < 0) return -1;
        int capK = min(k, maxCost);
        
        // dp[i][j][c] = max score achievable at (i,j) with cost c
        // Initialize with -1 (invalid)
        vector<vector<vector<int>>> dp(m, vector<vector<int>>(n, vector<int>(capK + 1, -1)));
        
        // Start cell (0,0): grid[0][0] == 0, so score=0, cost=0
        dp[0][0][0] = 0;
        
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                int val = grid[i][j];
                int sc = val;          // score contribution
                int co = (val > 0) ? 1 : 0; // cost contribution
                
                if (i == 0 && j == 0) continue; // already initialized
                
                for (int c = 0; c <= capK; c++) {
                    // come from top (i-1, j)
                    if (i > 0 && c >= co && dp[i-1][j][c - co] >= 0) {
                        dp[i][j][c] = max(dp[i][j][c], dp[i-1][j][c - co] + sc);
                    }
                    // come from left (i, j-1)
                    if (j > 0 && c >= co && dp[i][j-1][c - co] >= 0) {
                        dp[i][j][c] = max(dp[i][j][c], dp[i][j-1][c - co] + sc);
                    }
                }
            }
        }
        
        // Find max score at (m-1, n-1) with cost <= k
        int ans = -1;
        for (int c = 0; c <= capK; c++) {
            if (dp[m-1][n-1][c] >= 0) {
                ans = max(ans, dp[m-1][n-1][c]);
            }
        }
        return ans;
    }
};
