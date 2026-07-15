// @leetcode id=576 questionId=576 slug=out-of-boundary-paths lang=cpp site=leetcode.com title="Out of Boundary Paths"
class Solution {
public:
    int findPaths(int m, int n, int maxMove, int startRow, int startColumn) {
        const long long MOD = 1e9 + 7;
        vector<vector<long long>> dp(m, vector<long long>(n, 0));
        dp[startRow][startColumn] = 1;
        long long total = 0;

        int dr[] = {-1, 1, 0, 0};
        int dc[] = {0, 0, -1, 1};

        for (int move = 0; move < maxMove; move++) {
            vector<vector<long long>> ndp(m, vector<long long>(n, 0));
            for (int r = 0; r < m; r++) {
                for (int c = 0; c < n; c++) {
                    if (dp[r][c] == 0) continue;
                    for (int d = 0; d < 4; d++) {
                        int nr = r + dr[d], nc = c + dc[d];
                        if (nr < 0 || nr >= m || nc < 0 || nc >= n) {
                            total = (total + dp[r][c]) % MOD;
                        } else {
                            ndp[nr][nc] = (ndp[nr][nc] + dp[r][c]) % MOD;
                        }
                    }
                }
            }
            dp = ndp;
        }
        return (int)total;
    }
};
