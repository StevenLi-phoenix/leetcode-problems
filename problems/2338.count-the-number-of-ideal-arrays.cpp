// @leetcode id=2338 questionId=2415 slug=count-the-number-of-ideal-arrays lang=cpp site=leetcode.com title="Count the Number of Ideal Arrays"
class Solution {
public:
    int idealArrays(int n, int maxValue) {
        const long long MOD = 1e9 + 7;

        auto modpow = [&](long long a, long long b, long long m) -> long long {
            long long res = 1;
            a %= m;
            while (b > 0) {
                if (b & 1) res = res * a % m;
                a = a * a % m;
                b >>= 1;
            }
            return res;
        };

        vector<long long> fact(n), inv_fact(n);
        fact[0] = 1;
        for (int i = 1; i < n; i++) {
            fact[i] = fact[i - 1] * i % MOD;
        }
        inv_fact[n - 1] = modpow(fact[n - 1], MOD - 2, MOD);
        for (int i = n - 2; i >= 0; i--) {
            inv_fact[i] = inv_fact[i + 1] * (i + 1) % MOD;
        }

        auto C = [&](int a, int b) -> long long {
            if (b < 0 || b > a) return 0;
            return fact[a] * inv_fact[b] % MOD * inv_fact[a - b] % MOD;
        };

        long long ans = 0;

        function<void(int, int)> dfs = [&](int last, int len) {
            ans = (ans + C(n - 1, len - 1)) % MOD;
            for (int next = 2 * last; next <= maxValue; next += last) {
                dfs(next, len + 1);
            }
        };

        for (int start = 1; start <= maxValue; start++) {
            dfs(start, 1);
        }

        return ans;
    }
};
