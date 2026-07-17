// @leetcode id=1866 questionId=1996 slug=number-of-ways-to-rearrange-sticks-with-k-sticks-visible lang=cpp site=leetcode.com title="Number of Ways to Rearrange Sticks With K Sticks Visible"
class Solution {
public:
    int rearrangeSticks(int n, int k) {
        const long long MOD = 1000000007;
        vector<vector<long long>> dp(n + 1, vector<long long>(k + 1, 0));
        dp[0][0] = 1;

        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= k; j++) {
                dp[i][j] = (dp[i - 1][j - 1] + (long long)(i - 1) * dp[i - 1][j]) % MOD;
            }
        }

        return (int)dp[n][k];
    }
};
