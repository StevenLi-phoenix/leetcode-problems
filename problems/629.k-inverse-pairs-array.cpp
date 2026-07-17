// @leetcode id=629 questionId=629 slug=k-inverse-pairs-array lang=cpp site=leetcode.com title="K Inverse Pairs Array"
class Solution {
public:
    int kInversePairs(int n, int k) {
        const long long MOD = 1e9 + 7;
        vector<long long> dp(k + 1, 0);
        dp[0] = 1;

        for (int i = 1; i <= n; i++) {
            vector<long long> ndp(k + 1, 0);
            vector<long long> prefix(k + 2, 0);
            for (int j = 0; j <= k; j++) prefix[j + 1] = (prefix[j] + dp[j]) % MOD;

            for (int j = 0; j <= k; j++) {
                int lo = max(0, j - i + 1);
                ndp[j] = (prefix[j + 1] - prefix[lo] + MOD) % MOD;
            }

            dp = ndp;
        }

        return (int)dp[k];
    }
};
