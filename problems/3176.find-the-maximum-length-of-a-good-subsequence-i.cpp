// @leetcode id=3176 questionId=3456 slug=find-the-maximum-length-of-a-good-subsequence-i lang=cpp site=leetcode.com title="Find the Maximum Length of a Good Subsequence I"
class Solution {
public:
    int maximumLength(vector<int>& nums, int k) {
        int n = nums.size();
        vector<vector<int>> dp(n, vector<int>(k + 1, 1));
        int best = 1;
        for (int i = 0; i < n; i++) {
            for (int i2 = 0; i2 < i; i2++) {
                for (int j = 0; j <= k; j++) {
                    if (nums[i2] == nums[i]) {
                        dp[i][j] = max(dp[i][j], dp[i2][j] + 1);
                    } else if (j > 0) {
                        dp[i][j] = max(dp[i][j], dp[i2][j - 1] + 1);
                    }
                }
            }
            for (int j = 0; j <= k; j++) best = max(best, dp[i][j]);
        }
        return best;
    }
};
