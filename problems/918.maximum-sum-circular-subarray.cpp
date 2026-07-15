// @leetcode id=918 questionId=954 slug=maximum-sum-circular-subarray lang=cpp site=leetcode.com title="Maximum Sum Circular Subarray"
class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums) {
        int total = 0;
        int curMax = 0, maxSum = INT_MIN;
        int curMin = 0, minSum = INT_MAX;

        for (int x : nums) {
            total += x;
            curMax = max(curMax + x, x);
            maxSum = max(maxSum, curMax);
            curMin = min(curMin + x, x);
            minSum = min(minSum, curMin);
        }

        if (maxSum < 0) return maxSum;
        return max(maxSum, total - minSum);
    }
};
