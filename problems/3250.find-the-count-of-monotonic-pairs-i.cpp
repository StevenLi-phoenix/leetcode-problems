// @leetcode id=3250 questionId=3535 slug=find-the-count-of-monotonic-pairs-i lang=cpp site=leetcode.com title="Find the Count of Monotonic Pairs I"
class Solution {
public:
    int countOfPairs(vector<int>& nums) {
        // Let arr1[i] = a_i. arr2[i] = nums[i]-a_i >= 0 forces a_i in
        // [0, nums[i]]. arr1 non-decreasing needs a_{i+1} >= a_i; arr2
        // non-increasing needs a_{i+1} - a_i >= nums[i+1]-nums[i]. Combined:
        // a_{i+1} >= a_i + max(0, nums[i+1]-nums[i]). DP over a_i with
        // prefix sums makes each transition O(1) per value.
        const long long MOD = 1'000'000'007;
        int n = nums.size();

        vector<long long> dp(nums[0] + 1, 1);
        for (int i = 1; i < n; i++) {
            vector<long long> prefix(nums[i - 1] + 2, 0);
            for (int a = 0; a <= nums[i - 1]; a++) prefix[a + 1] = (prefix[a] + dp[a]) % MOD;

            int d = max(0, nums[i] - nums[i - 1]);
            vector<long long> ndp(nums[i] + 1, 0);
            for (int a2 = 0; a2 <= nums[i]; a2++) {
                int hi = a2 - d;
                if (hi < 0) continue;
                hi = min(hi, nums[i - 1]);
                ndp[a2] = prefix[hi + 1];
            }
            dp = move(ndp);
        }

        long long ans = 0;
        for (long long v : dp) ans = (ans + v) % MOD;
        return (int)ans;
    }
};
