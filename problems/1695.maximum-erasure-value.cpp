// @leetcode id=1695 questionId=1813 slug=maximum-erasure-value lang=cpp site=leetcode.com title="Maximum Erasure Value"
class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
        unordered_set<int> seen;
        int n = nums.size();
        int l = 0;
        long long curSum = 0, best = 0;
        for (int r = 0; r < n; r++) {
            while (seen.count(nums[r])) {
                seen.erase(nums[l]);
                curSum -= nums[l];
                l++;
            }
            seen.insert(nums[r]);
            curSum += nums[r];
            best = max(best, curSum);
        }
        return (int)best;
    }
};
