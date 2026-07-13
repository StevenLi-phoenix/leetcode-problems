// @leetcode id=2518 questionId=2601 slug=number-of-great-partitions lang=cpp site=leetcode.com title="Number of Great Partitions"
class Solution {
public:
    int countPartitions(vector<int>& nums, int k) {
        // If total < 2k, no partition can have both sides >= k, so the
        // answer is 0. Otherwise, by complementation, the count of subsets
        // with sum < k equals the count with sum > total-k, so bad
        // partitions = 2*countLess(k) exactly (no overlap possible once
        // total >= 2k). Any element >= k can never belong to a sum-<k
        // subset, so only elements < k matter for the subset-sum DP.
        const int MOD = 1e9 + 7;
        int n = nums.size();
        long long total = 0;
        for (int v : nums) total += v;
        if (total < 2LL * k) return 0;

        vector<long long> dp(k, 0);
        dp[0] = 1;
        for (int v : nums) {
            if (v >= k) continue;
            for (int s = k - 1; s >= v; s--) {
                dp[s] = (dp[s] + dp[s - v]) % MOD;
            }
        }

        long long countLess = 0;
        for (long long v : dp) countLess = (countLess + v) % MOD;

        long long pow2n = 1;
        for (int i = 0; i < n; i++) pow2n = (pow2n * 2) % MOD;

        long long ans = ((pow2n - 2 * countLess) % MOD + MOD) % MOD;
        return (int)ans;
    }
};
