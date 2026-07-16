// @leetcode id=3381 questionId=3653 slug=maximum-subarray-sum-with-length-divisible-by-k lang=cpp site=leetcode.com title="Maximum Subarray Sum With Length Divisible by K"
class Solution {
public:
    long long maxSubarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        vector<long long> minPrefix(k, LLONG_MAX);
        minPrefix[0] = 0;
        long long prefix = 0;
        long long best = LLONG_MIN;
        for (int j = 1; j <= n; j++) {
            prefix += nums[j - 1];
            int r = j % k;
            if (minPrefix[r] != LLONG_MAX) {
                best = max(best, prefix - minPrefix[r]);
            }
            minPrefix[r] = min(minPrefix[r], prefix);
        }
        return best;
    }
};
