// @leetcode id=2312 questionId=1376 slug=selling-pieces-of-wood lang=cpp site=leetcode.com title="Selling Pieces of Wood"
class Solution {
public:
    long long sellingWood(int m, int n, vector<vector<int>>& prices) {
        // dp[i][j] = max money from piece of size i x j
        vector<vector<long long>> dp(m + 1, vector<long long>(n + 1, 0));
        
        // Initialize with given prices
        for (auto& p : prices) {
            dp[p[0]][p[1]] = p[2];
        }
        
        // Fill DP
        for (int i = 1; i <= m; i++) {
            for (int j = 1; j <= n; j++) {
                // Try all horizontal cuts
                for (int k = 1; k < i; k++) {
                    dp[i][j] = max(dp[i][j], dp[k][j] + dp[i-k][j]);
                }
                // Try all vertical cuts
                for (int k = 1; k < j; k++) {
                    dp[i][j] = max(dp[i][j], dp[i][k] + dp[i][j-k]);
                }
            }
        }
        
        return dp[m][n];
    }
};
