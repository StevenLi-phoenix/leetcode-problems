// @leetcode id=2327 questionId=2408 slug=number-of-people-aware-of-a-secret lang=cpp site=leetcode.com title="Number of People Aware of a Secret"
class Solution {
public:
    int peopleAwareOfSecret(int n, int delay, int forget) {
        const long long MOD = 1e9 + 7;
        vector<long long> newCount(n + 1, 0);
        newCount[1] = 1;

        for (int d = 2; d <= n; d++) {
            long long sum = 0;
            for (int k = max(1, d - forget + 1); k <= d - delay; k++) {
                sum = (sum + newCount[k]) % MOD;
            }
            newCount[d] = sum;
        }

        long long total = 0;
        for (int d = max(1, n - forget + 1); d <= n; d++) {
            total = (total + newCount[d]) % MOD;
        }
        return (int)total;
    }
};
