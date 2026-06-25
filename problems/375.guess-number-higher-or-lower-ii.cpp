// @leetcode id=375 questionId=375 slug=guess-number-higher-or-lower-ii lang=cpp site=leetcode.com title="Guess Number Higher or Lower II"
class Solution {
public:
    int getMoneyAmount(int n) {
        // dp[i][j] = min cost to guarantee win in range [i, j]
        vector<vector<int>> dp(n + 2, vector<int>(n + 2, 0));
        
        // Fill for increasing lengths
        for (int len = 2; len <= n; len++) {
            for (int lo = 1; lo + len - 1 <= n; lo++) {
                int hi = lo + len - 1;
                dp[lo][hi] = INT_MAX;
                for (int k = lo; k <= hi; k++) {
                    int cost = k + max(
                        (k - 1 >= lo ? dp[lo][k-1] : 0),
                        (k + 1 <= hi ? dp[k+1][hi] : 0)
                    );
                    dp[lo][hi] = min(dp[lo][hi], cost);
                }
            }
        }
        
        return dp[1][n];
    }
};
