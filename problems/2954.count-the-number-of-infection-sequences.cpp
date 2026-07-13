// @leetcode id=2954 questionId=3224 slug=count-the-number-of-infection-sequences lang=cpp site=leetcode.com title="Count the Number of Infection Sequences"
class Solution {
public:
    int numberOfSequence(int n, vector<int>& sick) {
        const long long MOD = 1'000'000'007;
        int m = sick.size();

        vector<long long> fact(n + 1), invFact(n + 1);
        fact[0] = 1;
        for (int i = 1; i <= n; i++) fact[i] = fact[i - 1] * i % MOD;
        auto power = [&](long long b, long long e) {
            long long r = 1; b %= MOD;
            while (e > 0) { if (e & 1) r = r * b % MOD; b = b * b % MOD; e >>= 1; }
            return r;
        };
        invFact[n] = power(fact[n], MOD - 2);
        for (int i = n; i > 0; i--) invFact[i - 1] = invFact[i] * i % MOD;

        int totalHealthy = n - m;
        long long ans = fact[totalHealthy];

        // Boundary gaps (before the first / after the last sick person) can
        // only be infected in one order (spreading from the single sick
        // neighbor); internal gaps between two sick people can be infected
        // from either end, giving 2^(gap-1) interleavings.
        if (sick[0] > 0) {
            int gap = sick[0];
            ans = ans * invFact[gap] % MOD;
        }
        if (sick[m - 1] < n - 1) {
            int gap = n - 1 - sick[m - 1];
            ans = ans * invFact[gap] % MOD;
        }
        for (int i = 1; i < m; i++) {
            int gap = sick[i] - sick[i - 1] - 1;
            if (gap <= 0) continue;
            ans = ans * invFact[gap] % MOD;
            ans = ans * power(2, gap - 1) % MOD;
        }

        return (int)ans;
    }
};
