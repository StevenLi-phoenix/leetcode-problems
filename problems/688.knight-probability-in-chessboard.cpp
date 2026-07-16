// @leetcode id=688 questionId=688 slug=knight-probability-in-chessboard lang=cpp site=leetcode.com title="Knight Probability in Chessboard"
class Solution {
public:
    double knightProbability(int n, int k, int row, int column) {
        vector<vector<double>> dp(n, vector<double>(n, 0.0));
        dp[row][column] = 1.0;

        int dirs[8][2] = {{1,2},{1,-2},{-1,2},{-1,-2},{2,1},{2,-1},{-2,1},{-2,-1}};

        for (int step = 0; step < k; step++) {
            vector<vector<double>> ndp(n, vector<double>(n, 0.0));
            for (int r = 0; r < n; r++) {
                for (int c = 0; c < n; c++) {
                    if (dp[r][c] == 0.0) continue;
                    for (auto& d : dirs) {
                        int nr = r + d[0], nc = c + d[1];
                        if (nr >= 0 && nr < n && nc >= 0 && nc < n) {
                            ndp[nr][nc] += dp[r][c] / 8.0;
                        }
                    }
                }
            }
            dp = ndp;
        }

        double total = 0.0;
        for (int r = 0; r < n; r++) {
            for (int c = 0; c < n; c++) {
                total += dp[r][c];
            }
        }
        return total;
    }
};
