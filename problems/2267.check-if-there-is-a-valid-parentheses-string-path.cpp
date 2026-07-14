// @leetcode id=2267 questionId=2349 slug=check-if-there-is-a-valid-parentheses-string-path lang=cpp site=leetcode.com title=" Check if There Is a Valid Parentheses String Path"
class Solution {
public:
    bool hasValidPath(vector<vector<char>>& grid) {
        int m = grid.size(), n = grid[0].size();
        if ((m + n - 1) % 2 != 0) return false;

        // dp[i][j] = set of balance values (open minus closed count) reachable at (i,j).
        vector<vector<vector<bool>>> dp(m, vector<vector<bool>>(n, vector<bool>(m + n, false)));
        int delta0 = grid[0][0] == '(' ? 1 : -1;
        if (delta0 >= 0) dp[0][0][delta0] = true;

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (i == 0 && j == 0) continue;
                int delta = grid[i][j] == '(' ? 1 : -1;
                for (int b = 0; b < m + n; b++) {
                    int nb = b + delta;
                    if (nb < 0 || nb >= m + n) continue;
                    bool fromUp = (i > 0 && dp[i - 1][j][b]);
                    bool fromLeft = (j > 0 && dp[i][j - 1][b]);
                    if (fromUp || fromLeft) dp[i][j][nb] = true;
                }
            }
        }
        return dp[m - 1][n - 1][0];
    }
};
