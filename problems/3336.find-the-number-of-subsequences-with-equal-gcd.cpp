// @leetcode id=3336 questionId=3608 slug=find-the-number-of-subsequences-with-equal-gcd lang=cpp site=leetcode.com title="Find the Number of Subsequences With Equal GCD"
class Solution {
public:
    int subsequencePairCount(vector<int>& nums) {
        const long long MOD = 1000000007;
        const int V = 201;
        vector<vector<long long>> dp(V, vector<long long>(V, 0));
        dp[0][0] = 1;
        for (int x : nums) {
            vector<vector<long long>> ndp = dp;
            for (int g1 = 0; g1 < V; g1++) {
                int ng1 = (g1 == 0) ? x : __gcd(g1, x);
                for (int g2 = 0; g2 < V; g2++) {
                    if (dp[g1][g2]) {
                        ndp[ng1][g2] = (ndp[ng1][g2] + dp[g1][g2]) % MOD;
                    }
                }
            }
            for (int g2 = 0; g2 < V; g2++) {
                int ng2 = (g2 == 0) ? x : __gcd(g2, x);
                for (int g1 = 0; g1 < V; g1++) {
                    if (dp[g1][g2]) {
                        ndp[g1][ng2] = (ndp[g1][ng2] + dp[g1][g2]) % MOD;
                    }
                }
            }
            dp = ndp;
        }
        long long ans = 0;
        for (int g = 1; g < V; g++) ans = (ans + dp[g][g]) % MOD;
        return (int)ans;
    }
};
