// @leetcode id=1444 questionId=1555 slug=number-of-ways-of-cutting-a-pizza lang=cpp site=leetcode.com title="Number of Ways of Cutting a Pizza"
class Solution {
public:
    int ways(vector<string>& pizza, int k) {
        const int MOD = 1e9 + 7;
        int rows = pizza.size(), cols = pizza[0].size();

        vector<vector<int>> apples(rows + 1, vector<int>(cols + 1, 0));
        for (int r = rows - 1; r >= 0; --r) {
            for (int c = cols - 1; c >= 0; --c) {
                apples[r][c] = (pizza[r][c] == 'A' ? 1 : 0) + apples[r + 1][c] + apples[r][c + 1] - apples[r + 1][c + 1];
            }
        }

        vector<vector<vector<int>>> dp(k + 1, vector<vector<int>>(rows, vector<int>(cols, 0)));
        for (int r = 0; r < rows; ++r) {
            for (int c = 0; c < cols; ++c) {
                dp[1][r][c] = (apples[r][c] > 0) ? 1 : 0;
            }
        }

        for (int pieces = 2; pieces <= k; ++pieces) {
            for (int r = rows - 1; r >= 0; --r) {
                for (int c = cols - 1; c >= 0; --c) {
                    long long total = 0;
                    for (int nr = r + 1; nr < rows; ++nr) {
                        if (apples[r][c] - apples[nr][c] > 0) total += dp[pieces - 1][nr][c];
                    }
                    for (int nc = c + 1; nc < cols; ++nc) {
                        if (apples[r][c] - apples[r][nc] > 0) total += dp[pieces - 1][r][nc];
                    }
                    dp[pieces][r][c] = total % MOD;
                }
            }
        }

        return dp[k][0][0];
    }
};
