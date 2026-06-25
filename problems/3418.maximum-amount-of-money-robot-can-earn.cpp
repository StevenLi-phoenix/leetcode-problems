// @leetcode id=3418 questionId=3677 slug=maximum-amount-of-money-robot-can-earn lang=cpp site=leetcode.com title="Maximum Amount of Money Robot Can Earn"
class Solution {
    public:
    int maximumAmount(vector<vector<int>>& coins) {
    int m = coins.size(), n = coins[0].size();
    const int NEG_INF = INT_MIN / 2;
    vector<vector<array<int,3>>> dp(m, vector<array<int,3>>(n, {NEG_INF, NEG_INF, NEG_INF}));
    dp[0][0][0] = coins[0][0];
    if (coins[0][0] < 0) dp[0][0][1] = 0;
    for (int i = 1; i < m; i++) {
    for (int k = 0; k < 3; k++) {
    if (dp[i-1][0][k] == NEG_INF) continue;
    dp[i][0][k] = max(dp[i][0][k], dp[i-1][0][k] + coins[i][0]);
    if (coins[i][0] < 0 && k < 2)
    dp[i][0][k+1] = max(dp[i][0][k+1], dp[i-1][0][k]);
    }
    }
    for (int j = 1; j < n; j++) {
    for (int k = 0; k < 3; k++) {
    if (dp[0][j-1][k] == NEG_INF) continue;
    dp[0][j][k] = max(dp[0][j][k], dp[0][j-1][k] + coins[0][j]);
    if (coins[0][j] < 0 && k < 2)
    dp[0][j][k+1] = max(dp[0][j][k+1], dp[0][j-1][k]);
    }
    }
    for (int i = 1; i < m; i++) {
    for (int j = 1; j < n; j++) {
    for (int k = 0; k < 3; k++) {
    int prev = max(dp[i-1][j][k], dp[i][j-1][k]);
    if (prev == NEG_INF) continue;
    dp[i][j][k] = max(dp[i][j][k], prev + coins[i][j]);
    if (coins[i][j] < 0 && k < 2)
    dp[i][j][k+1] = max(dp[i][j][k+1], prev);
    }
    }
    }
    return max({dp[m-1][n-1][0], dp[m-1][n-1][1], dp[m-1][n-1][2]});
    }
    };
