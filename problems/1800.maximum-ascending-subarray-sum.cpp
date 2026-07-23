// @leetcode id=1800 questionId=1927 slug=maximum-ascending-subarray-sum lang=cpp site=leetcode.com title="Maximum Ascending Subarray Sum"
class Solution {
public:
    int maxAscendingSum(vector<int>& nums) {
        int best = nums[0], current = nums[0];
        for (int i = 1; i < (int)nums.size(); i++) {
            if (nums[i] > nums[i - 1]) {
                current += nums[i];
            } else {
                current = nums[i];
            }
            best = max(best, current);
        }
        return best;
    }
};
