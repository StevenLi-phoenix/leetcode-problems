// @leetcode id=2400 questionId=2477 slug=number-of-ways-to-reach-a-position-after-exactly-k-steps lang=cpp site=leetcode.com title="Number of Ways to Reach a Position After Exactly k Steps"
class Solution {
public:
    int numberOfWays(int startPos, int endPos, int k) {
        const long long MOD = 1e9 + 7;
        int d = abs(endPos - startPos);
        if (d > k || (d % 2) != (k % 2)) return 0;

        int n = k;
        vector<long long> fact(n + 1);
        fact[0] = 1;
        for (int i = 1; i <= n; i++) fact[i] = fact[i - 1] * i % MOD;

        vector<long long> inv(n + 1);
        inv[n] = modpow(fact[n], MOD - 2, MOD);
        for (int i = n; i > 0; i--) inv[i - 1] = inv[i] * i % MOD;

        int r = (k - d) / 2;
        return (int)(fact[n] * inv[r] % MOD * inv[n - r] % MOD);
    }

private:
    long long modpow(long long base, long long exp, long long mod) {
        long long result = 1;
        base %= mod;
        while (exp > 0) {
            if (exp & 1) result = result * base % mod;
            base = base * base % mod;
            exp >>= 1;
        }
        return result;
    }
};
