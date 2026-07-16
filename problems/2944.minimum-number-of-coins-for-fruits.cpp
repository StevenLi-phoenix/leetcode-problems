// @leetcode id=2944 questionId=3209 slug=minimum-number-of-coins-for-fruits lang=cpp site=leetcode.com title="Minimum Number of Coins for Fruits"
class Solution {
public:
    int minimumCoins(vector<int>& prices) {
        int n = prices.size();
        vector<int> dp(n + 1, INT_MAX);
        dp[0] = 0;
        for (int i = 1; i <= n; i++) {
            dp[i] = min(dp[i], dp[i - 1] + prices[i - 1]);
            int cost = dp[i - 1] + prices[i - 1];
            for (int j = i + 1; j <= min(n, 2 * i); j++) {
                dp[j] = min(dp[j], cost);
            }
        }
        return dp[n];
    }
};
