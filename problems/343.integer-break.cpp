// @leetcode id=343 questionId=343 slug=integer-break lang=cpp site=leetcode.com title="Integer Break"
class Solution {
public:
    int integerBreak(int n) {
        vector<long long> dp(n + 1, 0);
        dp[1] = 1;
        for (int i = 2; i <= n; i++) {
            for (int j = 1; j < i; j++) {
                dp[i] = max(dp[i], (long long)j * (i - j));
                dp[i] = max(dp[i], (long long)j * dp[i - j]);
            }
        }
        return (int)dp[n];
    }
};
