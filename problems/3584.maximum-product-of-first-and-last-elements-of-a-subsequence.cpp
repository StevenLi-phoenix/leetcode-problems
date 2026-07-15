// @leetcode id=3584 questionId=3755 slug=maximum-product-of-first-and-last-elements-of-a-subsequence lang=cpp site=leetcode.com title="Maximum Product of First and Last Elements of a Subsequence"
class Solution {
public:
    long long maximumProduct(vector<int>& nums, int m) {
        int n = nums.size();
        vector<int> suffixMax(n), suffixMin(n);
        suffixMax[n - 1] = suffixMin[n - 1] = nums[n - 1];
        for (int i = n - 2; i >= 0; i--) {
            suffixMax[i] = max(nums[i], suffixMax[i + 1]);
            suffixMin[i] = min(nums[i], suffixMin[i + 1]);
        }

        long long best = LLONG_MIN;
        for (int i = 0; i + m - 1 < n; i++) {
            int j = i + m - 1;
            best = max(best, (long long)nums[i] * suffixMax[j]);
            best = max(best, (long long)nums[i] * suffixMin[j]);
        }
        return best;
    }
};
