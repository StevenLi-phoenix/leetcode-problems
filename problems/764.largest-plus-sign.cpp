// @leetcode id=764 questionId=769 slug=largest-plus-sign lang=cpp site=leetcode.com title="Largest Plus Sign"
class Solution {
public:
    int orderOfLargestPlusSign(int n, vector<vector<int>>& mines) {
        vector<vector<bool>> mine(n, vector<bool>(n, false));
        for (auto& m : mines) mine[m[0]][m[1]] = true;

        vector<vector<int>> dp(n, vector<int>(n, 0));

        for (int i = 0; i < n; i++) {
            int count = 0;
            for (int j = 0; j < n; j++) {
                count = mine[i][j] ? 0 : count + 1;
                dp[i][j] = count;
            }
            count = 0;
            for (int j = n - 1; j >= 0; j--) {
                count = mine[i][j] ? 0 : count + 1;
                dp[i][j] = min(dp[i][j], count);
            }
        }

        for (int j = 0; j < n; j++) {
            int count = 0;
            for (int i = 0; i < n; i++) {
                count = mine[i][j] ? 0 : count + 1;
                dp[i][j] = min(dp[i][j], count);
            }
            count = 0;
            for (int i = n - 1; i >= 0; i--) {
                count = mine[i][j] ? 0 : count + 1;
                dp[i][j] = min(dp[i][j], count);
            }
        }

        int best = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                best = max(best, dp[i][j]);
            }
        }
        return best;
    }
};
