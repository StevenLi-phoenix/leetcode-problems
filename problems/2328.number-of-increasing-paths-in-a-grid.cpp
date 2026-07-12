// @leetcode id=2328 questionId=2409 slug=number-of-increasing-paths-in-a-grid lang=cpp site=leetcode.com title="Number of Increasing Paths in a Grid"
class Solution {
public:
    int countPaths(vector<vector<int>>& grid) {
        const long long MOD = 1'000'000'007;
        int m = grid.size(), n = grid[0].size();

        // Process cells in decreasing value order so that whenever we reach
        // a cell, every strictly-greater neighbor already has a final dp
        // value (avoids recursion-depth risk on long increasing chains).
        vector<int> order(m * n);
        for (int i = 0; i < m * n; i++) order[i] = i;
        sort(order.begin(), order.end(), [&](int a, int b) {
            return grid[a / n][a % n] > grid[b / n][b % n];
        });

        vector<long long> dp(m * n, 1);
        int dr[4] = {-1, 1, 0, 0}, dc[4] = {0, 0, -1, 1};
        for (int idx : order) {
            int r = idx / n, c = idx % n;
            for (int d = 0; d < 4; d++) {
                int nr = r + dr[d], nc = c + dc[d];
                if (nr < 0 || nr >= m || nc < 0 || nc >= n) continue;
                if (grid[nr][nc] > grid[r][c]) dp[idx] = (dp[idx] + dp[nr * n + nc]) % MOD;
            }
        }

        long long ans = 0;
        for (long long v : dp) ans = (ans + v) % MOD;
        return (int)ans;
    }
};
