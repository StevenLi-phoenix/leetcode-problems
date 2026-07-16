// @leetcode id=790 questionId=806 slug=domino-and-tromino-tiling lang=cpp site=leetcode.com title="Domino and Tromino Tiling"
class Solution {
public:
    int numTilings(int n) {
        const long long MOD = 1e9 + 7;
        if (n == 1) return 1;
        if (n == 2) return 2;

        vector<long long> dp(n + 1);
        dp[0] = 1;
        dp[1] = 1;
        dp[2] = 2;
        for (int i = 3; i <= n; i++) {
            dp[i] = (2 * dp[i - 1] % MOD + dp[i - 3]) % MOD;
        }
        return (int)dp[n];
    }
};
