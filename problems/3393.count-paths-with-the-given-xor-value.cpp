// @leetcode id=3393 questionId=3659 slug=count-paths-with-the-given-xor-value lang=cpp site=leetcode.com title="Count Paths With the Given XOR Value"
class Solution {
public:
    int countPathsWithXorValue(vector<vector<int>>& grid, int k) {
        int m = grid.size(), n = grid[0].size();
        const int MOD = 1e9 + 7;
        // dp[i][j][x] = number of paths to (i,j) with XOR = x
        vector<vector<vector<int>>> dp(m, vector<vector<int>>(n, vector<int>(16, 0)));
        dp[0][0][grid[0][0]] = 1;
        // Fill first row
        for (int j = 1; j < n; j++) {
            for (int x = 0; x < 16; x++) {
                dp[0][j][x ^ grid[0][j]] = (dp[0][j][x ^ grid[0][j]] + dp[0][j-1][x]) % MOD;
            }
        }
        // Fill first column
        for (int i = 1; i < m; i++) {
            for (int x = 0; x < 16; x++) {
                dp[i][0][x ^ grid[i][0]] = (dp[i][0][x ^ grid[i][0]] + dp[i-1][0][x]) % MOD;
            }
        }
        // Fill rest
        for (int i = 1; i < m; i++) {
            for (int j = 1; j < n; j++) {
                for (int x = 0; x < 16; x++) {
                    int nx = x ^ grid[i][j];
                    dp[i][j][nx] = (dp[i][j][nx] + dp[i-1][j][x] + dp[i][j-1][x]) % MOD;
                }
            }
        }
        return dp[m-1][n-1][k];
    }
};
