// @leetcode id=3757 questionId=4134 slug=number-of-effective-subsequences lang=cpp site=leetcode.com title="Number of Effective Subsequences"
class Solution {
public:
    int countEffective(vector<int>& nums) {
        const long long MOD = 1e9 + 7;
        int n = nums.size();

        int full = 0;
        for (int v : nums) full |= v;

        int BITS = (full == 0) ? 0 : (32 - __builtin_clz((unsigned)full));
        int U = 1 << BITS;

        vector<long long> subsetSum(U, 0);
        for (int v : nums) subsetSum[v]++;

        for (int b = 0; b < BITS; b++) {
            for (int mask = 0; mask < U; mask++) {
                if (mask & (1 << b)) subsetSum[mask] += subsetSum[mask ^ (1 << b)];
            }
        }

        vector<long long> pow2(n + 1, 1);
        for (int i = 1; i <= n; i++) pow2[i] = pow2[i - 1] * 2 % MOD;

        long long answer = 0;
        for (int T = full; T > 0; T = (T - 1) & full) {
            int compMask = full & (~T);
            long long freeCount = subsetSum[compMask];
            int bits = __builtin_popcount((unsigned)T);
            long long term = pow2[freeCount];
            if (bits % 2 == 1) answer = (answer + term) % MOD;
            else answer = (answer - term + MOD) % MOD;
        }

        return (int)answer;
    }
};
