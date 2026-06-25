// @leetcode id=1735 questionId=1836 slug=count-ways-to-make-array-with-product lang=cpp site=leetcode.com title="Count Ways to Make Array With Product"
class Solution {
public:
    const int MOD = 1e9 + 7;
    
    // Precompute factorials and inverse factorials for combinations
    vector<long long> fact, inv_fact;
    
    long long power(long long a, long long b, long long mod) {
        long long res = 1; a %= mod;
        while (b > 0) {
            if (b & 1) res = res * a % mod;
            a = a * a % mod;
            b >>= 1;
        }
        return res;
    }
    
    void precompute(int n) {
        fact.resize(n + 1);
        inv_fact.resize(n + 1);
        fact[0] = 1;
        for (int i = 1; i <= n; i++) fact[i] = fact[i-1] * i % MOD;
        inv_fact[n] = power(fact[n], MOD - 2, MOD);
        for (int i = n - 1; i >= 0; i--) inv_fact[i] = inv_fact[i+1] * (i+1) % MOD;
    }
    
    // C(n+k-1, k) = stars and bars: distribute k identical items into n bins
    long long comb(long long n, long long k) {
        // C(n+k-1, k)
        long long top = n + k - 1;
        if (top < 0 || k < 0) return 0;
        if (k == 0) return 1;
        // compute C(top, k) directly
        long long res = 1;
        for (long long i = 0; i < k; i++) {
            res = res % MOD * ((top - i) % MOD) % MOD;
            res = res % MOD * power(i + 1, MOD - 2, MOD) % MOD;
        }
        return res % MOD;
    }
    
    vector<int> waysToFillArray(vector<vector<int>>& queries) {
        vector<int> ans;
        for (auto& q : queries) {
            long long n = q[0], k = q[1];
            long long res = 1;
            // factorize k
            for (long long p = 2; p * p <= k; p++) {
                if (k % p == 0) {
                    int exp = 0;
                    while (k % p == 0) { exp++; k /= p; }
                    // distribute exp among n slots: C(n + exp - 1, exp)
                    res = res * comb(n, exp) % MOD;
                }
            }
            if (k > 1) res = res * comb(n, 1) % MOD; // remaining prime factor
            ans.push_back(res);
        }
        return ans;
    }
};
