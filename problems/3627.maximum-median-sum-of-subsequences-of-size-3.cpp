// @leetcode id=3627 questionId=3766 slug=maximum-median-sum-of-subsequences-of-size-3 lang=cpp site=leetcode.com title="Maximum Median Sum of Subsequences of Size 3"
class Solution {
public:
    long long maximumMedianSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        long long total = 0;
        for (int i = n / 3; i < n; i += 2) {
            total += nums[i];
        }
        return total;
    }
};
