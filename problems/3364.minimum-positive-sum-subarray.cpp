// @leetcode id=3364 questionId=3644 slug=minimum-positive-sum-subarray lang=cpp site=leetcode.com title="Minimum Positive Sum Subarray "
class Solution {
public:
    int minimumSumSubarray(vector<int>& nums, int l, int r) {
        int n = nums.size();
        vector<int> prefix(n + 1, 0);
        for (int i = 0; i < n; i++) prefix[i + 1] = prefix[i] + nums[i];

        int best = INT_MAX;
        for (int len = l; len <= r; len++) {
            for (int i = 0; i + len <= n; i++) {
                int sum = prefix[i + len] - prefix[i];
                if (sum > 0) best = min(best, sum);
            }
        }
        return best == INT_MAX ? -1 : best;
    }
};
