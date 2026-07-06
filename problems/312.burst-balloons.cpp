// @leetcode id=312 questionId=312 slug=burst-balloons lang=cpp site=leetcode.com title="Burst Balloons"
class Solution {
public:
    int maxCoins(vector<int>& nums) {
        int n = nums.size();
        vector<int> balloons(n + 2);
        balloons[0] = 1;
        balloons[n + 1] = 1;
        for (int i = 0; i < n; ++i) balloons[i + 1] = nums[i];

        vector<vector<int>> dp(n + 2, vector<int>(n + 2, 0));
        for (int len = 1; len <= n; ++len) {
            for (int l = 1; l + len - 1 <= n; ++l) {
                int r = l + len - 1;
                for (int k = l; k <= r; ++k) {
                    int coins = balloons[l - 1] * balloons[k] * balloons[r + 1]
                              + dp[l][k - 1] + dp[k + 1][r];
                    dp[l][r] = max(dp[l][r], coins);
                }
            }
        }
        return dp[1][n];
    }
};
