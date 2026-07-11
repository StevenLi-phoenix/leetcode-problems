// @leetcode id=2897 questionId=3153 slug=apply-operations-on-array-to-maximize-sum-of-squares lang=cpp site=leetcode.com title="Apply Operations on Array to Maximize Sum of Squares"
class Solution {
public:
    int maxSum(vector<int>& nums, int k) {
        // The operation redistributes set bits without changing the total count
        // per bit position, so greedily pack all available bits into k numbers.
        const long long MOD = 1'000'000'007;
        int cnt[30] = {};
        for (int x : nums)
            for (int b = 0; b < 30; b++)
                if (x >> b & 1) cnt[b]++;

        long long ans = 0;
        for (int i = 0; i < k; i++) {
            long long cur = 0;
            for (int b = 0; b < 30; b++)
                if (cnt[b] > 0) { cnt[b]--; cur |= 1LL << b; }
            ans = (ans + cur % MOD * (cur % MOD)) % MOD;
        }
        return ans;
    }
};
