// @leetcode id=3882 questionId=4205 slug=minimum-xor-path-in-a-grid lang=cpp site=leetcode.com title="Minimum XOR Path in a Grid"
class Solution {
public:
    int minCost(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        const int MAXXOR = 1024;
        vector<vector<bitset<1024>>> dp(m, vector<bitset<1024>>(n));
        
        dp[0][0].set(grid[0][0]);
        
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (i == 0 && j == 0) continue;
                
                bitset<1024> prev;
                if (i > 0) prev |= dp[i-1][j];
                if (j > 0) prev |= dp[i][j-1];
                
                int v = grid[i][j];
                // For each bit x set in prev, set bit x^v in dp[i][j]
                for (int x = 0; x < MAXXOR; x++) {
                    if (prev.test(x)) {
                        dp[i][j].set(x ^ v);
                    }
                }
            }
        }
        
        // Find minimum set bit in dp[m-1][n-1]
        for (int x = 0; x < MAXXOR; x++) {
            if (dp[m-1][n-1].test(x)) return x;
        }
        return -1;
    }
};
