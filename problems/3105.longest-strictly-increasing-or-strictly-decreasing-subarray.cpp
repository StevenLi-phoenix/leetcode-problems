// @leetcode id=3105 questionId=3372 slug=longest-strictly-increasing-or-strictly-decreasing-subarray lang=cpp site=leetcode.com title="Longest Strictly Increasing or Strictly Decreasing Subarray"
class Solution {
public:
    int longestMonotonicSubarray(vector<int>& nums) {
        int n = nums.size();
        int best = 1, inc = 1, dec = 1;
        for (int i = 1; i < n; i++) {
            if (nums[i] > nums[i - 1]) {
                inc++;
                dec = 1;
            } else if (nums[i] < nums[i - 1]) {
                dec++;
                inc = 1;
            } else {
                inc = 1;
                dec = 1;
            }
            best = max({best, inc, dec});
        }
        return best;
    }
};
