// @leetcode id=903 questionId=939 slug=valid-permutations-for-di-sequence lang=cpp site=leetcode.com title="Valid Permutations for DI Sequence"
class Solution {
public:
    int numPermsDISequence(string s) {
        const long long MOD = 1000000007;
        int n = s.size();

        vector<long long> dp(n + 1, 1);

        for (int i = 0; i < n; i++) {
            vector<long long> newDp(n + 1, 0);
            vector<long long> prefix(n + 2, 0);
            for (int j = 0; j <= i; j++) prefix[j + 1] = (prefix[j] + dp[j]) % MOD;

            if (s[i] == 'I') {
                for (int j = 0; j <= i + 1; j++) {
                    newDp[j] = prefix[j];
                }
            } else {
                for (int j = 0; j <= i + 1; j++) {
                    newDp[j] = (prefix[i + 1] - prefix[j] + MOD) % MOD;
                }
            }
            dp = newDp;
        }

        long long answer = 0;
        for (int j = 0; j <= n; j++) answer = (answer + dp[j]) % MOD;

        return (int)answer;
    }
};
