// @leetcode id=486 questionId=486 slug=predict-the-winner lang=cpp site=leetcode.com title="Predict the Winner"
class Solution {
public:
    bool predictTheWinner(vector<int>& nums) {
        // dp[i][j] = best score differential (current player minus opponent)
        // achievable on nums[i..j] when it's the current player's turn.
        int n = nums.size();
        vector<vector<int>> dp(n, vector<int>(n, 0));
        for (int i = 0; i < n; i++) dp[i][i] = nums[i];

        for (int len = 2; len <= n; len++) {
            for (int i = 0; i + len - 1 < n; i++) {
                int j = i + len - 1;
                dp[i][j] = max(nums[i] - dp[i + 1][j], nums[j] - dp[i][j - 1]);
            }
        }
        return dp[0][n - 1] >= 0;
    }
};
