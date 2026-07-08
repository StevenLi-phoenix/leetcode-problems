// @leetcode id=53 questionId=53 slug=maximum-subarray lang=cpp site=leetcode.com title="Maximum Subarray"
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int best = nums[0];
        int cur = nums[0];
        for (int i = 1; i < (int)nums.size(); ++i) {
            cur = max(nums[i], cur + nums[i]);
            best = max(best, cur);
        }
        return best;
    }
};
