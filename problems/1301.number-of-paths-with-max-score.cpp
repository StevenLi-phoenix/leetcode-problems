// @leetcode id=1301 questionId=1234 slug=number-of-paths-with-max-score lang=cpp site=leetcode.com title="Number of Paths with Max Score"
class Solution {
public:
    vector<int> pathsWithMaxScore(vector<string>& board) {
        int n = board.size();
        const long long MOD = 1000000007LL;
        vector<vector<long long>> dp(n, vector<long long>(n, -1));
        vector<vector<long long>> cnt(n, vector<long long>(n, 0));
        dp[n-1][n-1] = 0;
        cnt[n-1][n-1] = 1;
        int di[3] = {1,0,1};
        int dj[3] = {0,1,1};
        for (int i = n-1; i >= 0; i--) {
            for (int j = n-1; j >= 0; j--) {
                if (i == n-1 && j == n-1) continue;
                if (board[i][j] == 'X') continue;
                long long best = -1, ways = 0;
                for (int k = 0; k < 3; k++) {
                    int ni = i + di[k], nj = j + dj[k];
                    if (ni < n && nj < n && dp[ni][nj] != -1) {
                        if (dp[ni][nj] > best) {
                            best = dp[ni][nj];
                            ways = cnt[ni][nj];
                        } else if (dp[ni][nj] == best) {
                            ways = (ways + cnt[ni][nj]) % MOD;
                        }
                    }
                }
                if (best == -1) continue;
                int val = (board[i][j] == 'E') ? 0 : (board[i][j] - '0');
                dp[i][j] = best + val;
                cnt[i][j] = ways;
            }
        }
        if (dp[0][0] == -1) return {0,0};
        return {(int)dp[0][0], (int)cnt[0][0]};
    }
};
