// @leetcode id=2572 questionId=2709 slug=count-the-number-of-square-free-subsets lang=cpp site=leetcode.com title="Count the Number of Square-Free Subsets"
class Solution {
public:
    int squareFreeSubsets(vector<int>& nums) {
        // Values up to 30 factor over only 10 primes. Any value with a
        // repeated prime factor can never appear in a valid subset at all
        // (its own product already isn't square-free). 1s can be freely
        // included/excluded independently (2^count multiplier). Everything
        // else is a bitmask-knapsack over disjoint prime-usage.
        const int MOD = 1e9 + 7;
        vector<int> primes = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29};

        vector<int> freq(31, 0);
        for (int v : nums) freq[v]++;

        int numOnes = freq[1];

        vector<pair<int, int>> distinctVals; // {mask, count}
        for (int v = 2; v <= 30; v++) {
            if (freq[v] == 0) continue;
            int mask = 0;
            int t = v;
            bool squareFree = true;
            for (int pi = 0; pi < (int)primes.size(); pi++) {
                int p = primes[pi];
                if (t % p == 0) {
                    int cnt = 0;
                    while (t % p == 0) {
                        t /= p;
                        cnt++;
                    }
                    if (cnt > 1) {
                        squareFree = false;
                        break;
                    }
                    mask |= (1 << pi);
                }
            }
            if (squareFree) distinctVals.push_back({mask, freq[v]});
        }

        vector<long long> dp(1024, 0);
        dp[0] = 1;
        for (auto& [vmask, cnt] : distinctVals) {
            vector<long long> newDp = dp;
            for (int mask = 0; mask < 1024; mask++) {
                if (dp[mask] == 0) continue;
                if (mask & vmask) continue;
                newDp[mask | vmask] = (newDp[mask | vmask] + dp[mask] * cnt) % MOD;
            }
            dp = newDp;
        }

        long long sumAll = 0;
        for (long long v : dp) sumAll = (sumAll + v) % MOD;

        long long pow2 = 1;
        for (int i = 0; i < numOnes; i++) pow2 = (pow2 * 2) % MOD;

        long long ans = (sumAll * pow2 % MOD - 1 + MOD) % MOD;
        return (int)ans;
    }
};
