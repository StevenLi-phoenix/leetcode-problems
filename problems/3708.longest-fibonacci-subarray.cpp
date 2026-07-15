// @leetcode id=3708 questionId=4003 slug=longest-fibonacci-subarray lang=cpp site=leetcode.com title="Longest Fibonacci Subarray"
class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int n = nums.size();
        if (n < 2) return n;
        int best = 2, cur = 2;
        for (int i = 2; i < n; i++) {
            long long a = nums[i - 2], b = nums[i - 1];
            if (a + b == nums[i]) {
                cur++;
            } else {
                cur = 2;
            }
            best = max(best, cur);
        }
        return best;
    }
};
