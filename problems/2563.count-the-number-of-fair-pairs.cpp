// @leetcode id=2563 questionId=2699 slug=count-the-number-of-fair-pairs lang=cpp site=leetcode.com title="Count the Number of Fair Pairs"
class Solution {
public:
    long long countFairPairs(vector<int>& nums, int lower, int upper) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        
        long long count = 0;
        for (int i = 0; i < n - 1; i++) {
            // Find range in nums[i+1..n-1] where nums[j] is in [lower-nums[i], upper-nums[i]]
            int lo = lower - nums[i];
            int hi = upper - nums[i];
            
            // lower_bound for lo
            auto left = lower_bound(nums.begin() + i + 1, nums.end(), lo);
            // upper_bound for hi
            auto right = upper_bound(nums.begin() + i + 1, nums.end(), hi);
            
            count += right - left;
        }
        
        return count;
    }
};
