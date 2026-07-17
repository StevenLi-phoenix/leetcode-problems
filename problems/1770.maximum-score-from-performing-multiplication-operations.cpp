// @leetcode id=1770 questionId=1896 slug=maximum-score-from-performing-multiplication-operations lang=cpp site=leetcode.com title="Maximum Score from Performing Multiplication Operations"
class Solution {
public:
    int maximumScore(vector<int>& nums, vector<int>& multipliers) {
        int n = nums.size(), m = multipliers.size();
        vector<int> dp(m + 1, 0);

        for (int i = m - 1; i >= 0; i--) {
            vector<int> newDp(m + 1, 0);
            for (int left = i; left >= 0; left--) {
                int right = n - 1 - (i - left);
                int useLeft = multipliers[i] * nums[left] + dp[left + 1];
                int useRight = multipliers[i] * nums[right] + dp[left];
                newDp[left] = max(useLeft, useRight);
            }
            dp = newDp;
        }

        return dp[0];
    }
};
