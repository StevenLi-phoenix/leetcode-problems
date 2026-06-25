// @leetcode id=2915 questionId=3106 slug=length-of-the-longest-subsequence-that-sums-to-target lang=cpp site=leetcode.com title="Length of the Longest Subsequence That Sums to Target"
class Solution {
public:
    int lengthOfLongestSubsequence(vector<int>& nums, int target) {
        // dp[i] = maximum length of subsequence with sum = i
        vector<int> dp(target + 1, -1);
        dp[0] = 0;  // empty subsequence has sum 0 with length 0
        
        for (int num : nums) {
            // Traverse from right to left to avoid using the same element twice
            for (int j = target; j >= num; j--) {
                if (dp[j - num] != -1) {
                    dp[j] = max(dp[j], dp[j - num] + 1);
                }
            }
        }
        
        return dp[target];
    }
};
