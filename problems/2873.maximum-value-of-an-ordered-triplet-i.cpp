// @leetcode id=2873 questionId=3154 slug=maximum-value-of-an-ordered-triplet-i lang=cpp site=leetcode.com title="Maximum Value of an Ordered Triplet I"
class Solution {
public:
    long long maximumTripletValue(vector<int>& nums) {
        int n = nums.size();
        long long best = 0;
        long long maxPrefix = 0, maxDiff = 0;
        for (int k = 0; k < n; k++) {
            best = max(best, maxDiff * nums[k]);
            maxDiff = max(maxDiff, maxPrefix - nums[k]);
            maxPrefix = max(maxPrefix, (long long)nums[k]);
        }
        return best;
    }
};
