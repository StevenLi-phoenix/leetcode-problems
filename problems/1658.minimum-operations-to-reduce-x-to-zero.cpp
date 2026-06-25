// @leetcode id=1658 questionId=1776 slug=minimum-operations-to-reduce-x-to-zero lang=cpp site=leetcode.com title="Minimum Operations to Reduce X to Zero"
class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        int n = nums.size();
        int total = 0;
        for (int num : nums) total += num;
        
        int target = total - x;
        
        if (target < 0) return -1;
        if (target == 0) return n;
        
        // Find maximum length subarray with sum == target
        int maxLen = -1;
        int curSum = 0;
        int left = 0;
        
        for (int right = 0; right < n; right++) {
            curSum += nums[right];
            while (curSum > target && left <= right) {
                curSum -= nums[left++];
            }
            if (curSum == target) {
                maxLen = max(maxLen, right - left + 1);
            }
        }
        
        return maxLen == -1 ? -1 : n - maxLen;
    }
};
