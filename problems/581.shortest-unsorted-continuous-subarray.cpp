// @leetcode id=581 questionId=581 slug=shortest-unsorted-continuous-subarray lang=cpp site=leetcode.com title="Shortest Unsorted Continuous Subarray"
class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        int n = nums.size();
        int maxSoFar = INT_MIN, right = -1;
        int minSoFar = INT_MAX, left = n;
        for (int i = 0; i < n; i++) {
            maxSoFar = max(maxSoFar, nums[i]);
            if (nums[i] < maxSoFar) right = i;
        }
        for (int i = n - 1; i >= 0; i--) {
            minSoFar = min(minSoFar, nums[i]);
            if (nums[i] > minSoFar) left = i;
        }
        return right < left ? 0 : right - left + 1;
    }
};
