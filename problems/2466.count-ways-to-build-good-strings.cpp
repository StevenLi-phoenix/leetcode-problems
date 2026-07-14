// @leetcode id=2466 questionId=2562 slug=count-ways-to-build-good-strings lang=cpp site=leetcode.com title="Count Ways To Build Good Strings"
class Solution {
public:
    int countGoodStrings(int low, int high, int zero, int one) {
        const long long MOD = 1e9 + 7;
        vector<long long> dp(high + 1, 0);
        dp[0] = 1;
        long long total = 0;

        for (int len = 1; len <= high; len++) {
            if (len >= zero) dp[len] = (dp[len] + dp[len - zero]) % MOD;
            if (len >= one) dp[len] = (dp[len] + dp[len - one]) % MOD;
            if (len >= low) total = (total + dp[len]) % MOD;
        }
        return (int)total;
    }
};
