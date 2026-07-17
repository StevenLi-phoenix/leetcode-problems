// @leetcode id=2088 questionId=2193 slug=count-fertile-pyramids-in-a-land lang=cpp site=leetcode.com title="Count Fertile Pyramids in a Land"
class Solution {
public:
    int countPyramids(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        long long total = 0;

        // normal pyramids: apex at top, grows downward
        {
            vector<vector<int>> dp(m, vector<int>(n, 0));
            for (int i = m - 1; i >= 0; i--) {
                for (int j = 0; j < n; j++) {
                    if (!grid[i][j]) { dp[i][j] = 0; continue; }
                    if (i == m - 1 || j == 0 || j == n - 1) {
                        dp[i][j] = 1;
                    } else {
                        dp[i][j] = 1 + min({dp[i+1][j-1], dp[i+1][j], dp[i+1][j+1]});
                    }
                    total += dp[i][j] - 1;
                }
            }
        }

        // inverse pyramids: apex at bottom, grows upward
        {
            vector<vector<int>> dp(m, vector<int>(n, 0));
            for (int i = 0; i < m; i++) {
                for (int j = 0; j < n; j++) {
                    if (!grid[i][j]) { dp[i][j] = 0; continue; }
                    if (i == 0 || j == 0 || j == n - 1) {
                        dp[i][j] = 1;
                    } else {
                        dp[i][j] = 1 + min({dp[i-1][j-1], dp[i-1][j], dp[i-1][j+1]});
                    }
                    total += dp[i][j] - 1;
                }
            }
        }

        return (int)total;
    }
};
