// @leetcode id=2218 questionId=1393 slug=maximum-value-of-k-coins-from-piles lang=cpp site=leetcode.com title="Maximum Value of K Coins From Piles"
class Solution {
public:
    int maxValueOfCoins(vector<vector<int>>& piles, int k) {
        int n = piles.size();
        // dp[j] = max value picking exactly j coins from piles considered so far
        vector<int> dp(k + 1, 0);
        
        for (int i = 0; i < n; i++) {
            // Compute prefix sums for this pile
            vector<int>& pile = piles[i];
            int m = pile.size();
            vector<int> prefixSum(m + 1, 0);
            for (int t = 0; t < m; t++) {
                prefixSum[t + 1] = prefixSum[t] + pile[t];
            }
            
            // Traverse dp in reverse to avoid using same pile twice
            for (int j = k; j >= 0; j--) {
                // Take t coins from pile i
                for (int t = 1; t <= min(j, m); t++) {
                    dp[j] = max(dp[j], dp[j - t] + prefixSum[t]);
                }
            }
        }
        
        return dp[k];
    }
};
