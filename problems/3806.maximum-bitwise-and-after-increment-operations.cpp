// @leetcode id=3806 questionId=4154 slug=maximum-bitwise-and-after-increment-operations lang=cpp site=leetcode.com title="Maximum Bitwise AND After Increment Operations"
class Solution {
public:
    long long minCostFor(long long n, long long mask) {
        long long diff = mask & (~n);
        if (diff == 0) return 0;
        int highestMissingBit = 63 - __builtin_clzll(diff);
        long long lowMask = (1LL << highestMissingBit) - 1;
        long long v = (n & ~lowMask) + (1LL << highestMissingBit);
        v |= mask;
        return v - n;
    }

    bool feasible(vector<int>& nums, long long X, long long k, int m) {
        int n = nums.size();
        vector<long long> costs(n);
        for (int i = 0; i < n; i++) {
            costs[i] = minCostFor(nums[i], X);
        }
        sort(costs.begin(), costs.end());
        long long sum = 0;
        for (int i = 0; i < m; i++) sum += costs[i];
        return sum <= k;
    }

    int maximumAND(vector<int>& nums, int k, int m) {
        long long X = 0;
        for (int bit = 30; bit >= 0; bit--) {
            long long candidate = X | (1LL << bit);
            if (feasible(nums, candidate, k, m)) {
                X = candidate;
            }
        }
        return (int)X;
    }
};
