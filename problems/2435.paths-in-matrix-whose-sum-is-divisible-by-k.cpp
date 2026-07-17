// @leetcode id=2435 questionId=2521 slug=paths-in-matrix-whose-sum-is-divisible-by-k lang=cpp site=leetcode.com title="Paths in Matrix Whose Sum Is Divisible by K"
class Solution {
public:
    int numberOfPaths(vector<vector<int>>& grid, int k) {
        const long long MOD = 1000000007;
        int m = grid.size(), n = grid[0].size();

        vector<vector<vector<long long>>> dp(m, vector<vector<long long>>(n, vector<long long>(k, 0)));

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                int val = grid[i][j] % k;
                if (i == 0 && j == 0) {
                    dp[i][j][val] = 1;
                    continue;
                }
                for (int r = 0; r < k; r++) {
                    long long ways = 0;
                    if (i > 0) ways += dp[i-1][j][r];
                    if (j > 0) ways += dp[i][j-1][r];
                    ways %= MOD;
                    int newR = (r + val) % k;
                    dp[i][j][newR] = (dp[i][j][newR] + ways) % MOD;
                }
            }
        }

        return (int)dp[m-1][n-1][0];
    }
};
