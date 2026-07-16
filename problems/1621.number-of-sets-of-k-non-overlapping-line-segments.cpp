// @leetcode id=1621 questionId=1725 slug=number-of-sets-of-k-non-overlapping-line-segments lang=cpp site=leetcode.com title="Number of Sets of K Non-Overlapping Line Segments"
class Solution {
public:
    int numberOfSets(int n, int k) {
        const long long MOD = 1e9 + 7;
        vector<vector<long long>> dp(n + 1, vector<long long>(k + 1, 0));
        for (int i = 0; i <= n; i++) dp[i][0] = 1;

        for (int j = 1; j <= k; j++) {
            long long prefix = 0;
            for (int i = 1; i <= n; i++) {
                dp[i][j] = (dp[i - 1][j] + prefix) % MOD;
                prefix = (prefix + dp[i][j - 1]) % MOD;
            }
        }
        return (int)dp[n][k];
    }
};
