// @leetcode id=1690 questionId=1808 slug=stone-game-vii lang=cpp site=leetcode.com title="Stone Game VII"
class Solution {
public:
    int stoneGameVII(vector<int>& stones) {
        int n = stones.size();
        vector<int> prefix(n + 1, 0);
        for (int i = 0; i < n; ++i) prefix[i + 1] = prefix[i] + stones[i];

        vector<vector<int>> dp(n, vector<int>(n, 0));
        for (int len = 2; len <= n; ++len) {
            for (int i = 0; i + len - 1 < n; ++i) {
                int j = i + len - 1;
                int sumMinusRight = prefix[j] - prefix[i];       // removing right (j)
                int sumMinusLeft = prefix[j + 1] - prefix[i + 1]; // removing left (i)
                dp[i][j] = max(sumMinusRight - dp[i][j - 1], sumMinusLeft - dp[i + 1][j]);
            }
        }
        return dp[0][n - 1];
    }
};
