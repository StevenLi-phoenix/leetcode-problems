// @leetcode id=3665 questionId=3938 slug=twisted-mirror-path-count lang=cpp site=leetcode.com title="Twisted Mirror Path Count"
class Solution {
public:
    int uniquePaths(vector<vector<int>>& grid) {
        const long long MOD = 1e9 + 7;
        int m = grid.size(), n = grid[0].size();

        // landRight[r][c] / landDown[r][c]: final landing cell when attempting
        // to move into (r,c) from the left / from above, resolving any chain
        // of mirror reflections. {-1,-1} means the move goes out of bounds.
        vector<vector<pair<int,int>>> landRight(m, vector<pair<int,int>>(n));
        vector<vector<pair<int,int>>> landDown(m, vector<pair<int,int>>(n));

        for (int r = m - 1; r >= 0; r--) {
            for (int c = n - 1; c >= 0; c--) {
                if (grid[r][c] == 0) {
                    landRight[r][c] = {r, c};
                    landDown[r][c] = {r, c};
                } else {
                    landRight[r][c] = (r + 1 < m) ? landDown[r + 1][c] : make_pair(-1, -1);
                    landDown[r][c] = (c + 1 < n) ? landRight[r][c + 1] : make_pair(-1, -1);
                }
            }
        }

        vector<vector<long long>> dp(m, vector<long long>(n, 0));
        dp[0][0] = 1;

        for (int d = 0; d <= m + n - 2; d++) {
            int rLo = max(0, d - (n - 1));
            int rHi = min(d, m - 1);
            for (int r = rLo; r <= rHi; r++) {
                int c = d - r;
                if (dp[r][c] == 0) continue;
                long long ways = dp[r][c];

                if (c + 1 < n) {
                    auto [tr, tc] = landRight[r][c + 1];
                    if (tr != -1) dp[tr][tc] = (dp[tr][tc] + ways) % MOD;
                }
                if (r + 1 < m) {
                    auto [tr, tc] = landDown[r + 1][c];
                    if (tr != -1) dp[tr][tc] = (dp[tr][tc] + ways) % MOD;
                }
            }
        }

        return (int)(dp[m - 1][n - 1] % MOD);
    }
};
