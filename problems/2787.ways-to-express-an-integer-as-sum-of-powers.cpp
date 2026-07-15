// @leetcode id=2787 questionId=2882 slug=ways-to-express-an-integer-as-sum-of-powers lang=cpp site=leetcode.com title="Ways to Express an Integer as Sum of Powers"
class Solution {
public:
    int numberOfWays(int n, int x) {
        const long long MOD = 1e9 + 7;
        vector<long long> dp(n + 1, 0);
        dp[0] = 1;

        for (int i = 1; i <= n; i++) {
            long long power = 1;
            for (int e = 0; e < x; e++) power *= i;
            if (power > n) break;
            for (int t = n; t >= power; t--) {
                dp[t] = (dp[t] + dp[t - power]) % MOD;
            }
        }
        return (int)dp[n];
    }
};
