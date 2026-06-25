// @leetcode id=2770 questionId=2855 slug=maximum-number-of-jumps-to-reach-the-last-index lang=cpp site=leetcode.com title="Maximum Number of Jumps to Reach the Last Index"
class Solution {
public:
    int maximumJumps(vector<int>& nums, int target) {
        int n = nums.size();
        vector<int> dp(n, -1);
        dp[0] = 0;
        for (int j = 1; j < n; j++) {
            for (int i = 0; i < j; i++) {
                if (dp[i] != -1 && abs(nums[j] - nums[i]) <= target) {
                    dp[j] = max(dp[j], dp[i] + 1);
                }
            }
        }
        return dp[n - 1];
    }
};
