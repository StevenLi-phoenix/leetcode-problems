// @leetcode id=2680 questionId=2730 slug=maximum-or lang=cpp site=leetcode.com title="Maximum OR"
class Solution {
public:
    long long maximumOr(vector<int>& nums, int k) {
        int n = nums.size();
        vector<long long> prefix(n + 1, 0), suffix(n + 1, 0);
        for (int i = 0; i < n; i++) prefix[i + 1] = prefix[i] | nums[i];
        for (int i = n - 1; i >= 0; i--) suffix[i] = suffix[i + 1] | nums[i];

        long long best = 0;
        for (int i = 0; i < n; i++) {
            long long boosted = (long long)nums[i] << k;
            long long total = prefix[i] | boosted | suffix[i + 1];
            best = max(best, total);
        }
        return best;
    }
};
