// @leetcode id=3405 questionId=3682 slug=count-the-number-of-arrays-with-k-matching-adjacent-elements lang=cpp site=leetcode.com title="Count the Number of Arrays with K Matching Adjacent Elements"
class Solution {
    public:
    const long long MOD = 1e9 + 7;
    long long power(long long base, long long exp, long long mod) {
        long long result = 1;
        base %= mod;
        while (exp > 0) {
        if (exp & 1) result = result * base % mod;
        base = base * base % mod;
        exp >>= 1;
        }
        return result;
        }
        int countGoodArrays(int n, int m, int k) {
        long long mod = MOD;
        vector<long long> fact(n + 1);
        fact[0] = 1;
        for (int i = 1; i <= n; i++) fact[i] = fact[i-1] * i % mod;
        auto inv = [&](long long x) { return power(x, mod - 2, mod); };
        auto C = [&](int a, int b) -> long long {
        if (b < 0 || b > a) return 0;
        return fact[a] % mod * inv(fact[b]) % mod * inv(fact[a-b]) % mod;
        };
        long long ans = C(n-1, k) % mod;
        ans = ans * m % mod;
        ans = ans * power(m-1, n-1-k, mod) % mod;
        return (int)ans;
        }
        };
