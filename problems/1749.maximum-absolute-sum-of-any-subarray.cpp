// @leetcode id=1749 questionId=1849 slug=maximum-absolute-sum-of-any-subarray lang=cpp site=leetcode.com title="Maximum Absolute Sum of Any Subarray"
class Solution {
public:
    int maxAbsoluteSum(vector<int>& nums) {
        int maxSum = 0, minSum = 0;
        int curMax = 0, curMin = 0;
        for (int v : nums) {
            curMax = max(0, curMax) + v;
            curMin = min(0, curMin) + v;
            maxSum = max(maxSum, curMax);
            minSum = min(minSum, curMin);
        }
        return max(maxSum, -minSum);
    }
};
