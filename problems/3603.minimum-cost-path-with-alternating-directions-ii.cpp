// @leetcode id=3603 questionId=3927 slug=minimum-cost-path-with-alternating-directions-ii lang=cpp site=leetcode.com title="Minimum Cost Path with Alternating Directions II"
class Solution {
public:
    long long minCost(int m, int n, vector<vector<int>>& waitCost) {
        vector<vector<long long>> dp(m, vector<long long>(n, 0));
        auto entry = [](int i, int j) { return (long long)(i + 1) * (j + 1); };

        dp[0][0] = 1;
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (i == 0 && j == 0) continue;
                long long best = LLONG_MAX;
                if (i > 0) {
                    long long wait = (i - 1 == 0 && j == 0) ? 0 : waitCost[i - 1][j];
                    best = min(best, dp[i - 1][j] + wait);
                }
                if (j > 0) {
                    long long wait = (i == 0 && j - 1 == 0) ? 0 : waitCost[i][j - 1];
                    best = min(best, dp[i][j - 1] + wait);
                }
                dp[i][j] = best + entry(i, j);
            }
        }
        return dp[m - 1][n - 1];
    }
};
