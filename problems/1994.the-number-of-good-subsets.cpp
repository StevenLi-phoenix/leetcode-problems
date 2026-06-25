// @leetcode id=1994 questionId=2105 slug=the-number-of-good-subsets lang=cpp site=leetcode.com title="The Number of Good Subsets"
class Solution {
public:
    int numberOfGoodSubsets(vector<int>& nums) {
        const int MOD = 1e9 + 7;
        vector<int> primes = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29};
        int P = primes.size(); // 10 primes
        
        // Count frequencies
        vector<int> cnt(31, 0);
        for (int x : nums) cnt[x]++;
        
        // For each value 2..30, compute prime mask (or -1 if not squarefree)
        vector<int> pmask(31, 0);
        for (int v = 2; v <= 30; v++) {
            int x = v;
            bool ok = true;
            for (int i = 0; i < P; i++) {
                int p = primes[i];
                if (x % p == 0) {
                    x /= p;
                    if (x % p == 0) { ok = false; break; } // p^2 divides v
                    pmask[v] |= (1 << i);
                }
            }
            if (!ok) pmask[v] = -1;
        }
        
        // DP
        int FULL = 1 << P;
        vector<long long> dp(FULL, 0);
        dp[0] = 1; // empty subset
        
        for (int v = 2; v <= 30; v++) {
            if (cnt[v] == 0 || pmask[v] == -1) continue;
            int vm = pmask[v];
            // Iterate in reverse to avoid using v multiple times... but actually we can use
            // each distinct value multiple times (count[v] copies)
            // Wait: we're building subsets of indices, so we can include 0 or 1 copies of each value v.
            // But there are count[v] different indices with value v, and we can include any one of them.
            // So for value v with count[v] copies, we can choose 0 or 1 copies from count[v] options.
            // (Can't include 2 copies of same value because product would have repeated primes)
            
            // Transition: for each mask without vm, dp[mask|vm] += dp[mask] * cnt[v]
            for (int mask = FULL - 1; mask >= 0; mask--) {
                if ((mask & vm) != 0) continue;
                if (dp[mask] == 0) continue;
                dp[mask | vm] = (dp[mask | vm] + dp[mask] % MOD * cnt[v]) % MOD;
            }
        }
        
        // Sum all dp[mask] for mask != 0
        long long ans = 0;
        for (int mask = 1; mask < FULL; mask++) {
            ans = (ans + dp[mask]) % MOD;
        }
        
        // Multiply by 2^cnt[1] (each 1 can be in or out of any good subset)
        long long pow2 = 1;
        for (int i = 0; i < cnt[1]; i++) pow2 = pow2 * 2 % MOD;
        
        ans = ans * pow2 % MOD;
        
        return (int)ans;
    }
};
