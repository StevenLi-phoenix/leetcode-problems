// @leetcode id=3366 questionId=3654 slug=minimum-array-sum lang=cpp site=leetcode.com title="Minimum Array Sum"
class Solution {
public:
    int minArraySum(vector<int>& nums, int k, int op1, int op2) {
        const int INF = INT_MAX / 2;
        vector<vector<int>> dp(op1 + 1, vector<int>(op2 + 1, INF));
        dp[0][0] = 0;

        for (int x : nums) {
            int v00 = x;
            int v10 = (x + 1) / 2;
            int v01 = (x >= k) ? x - k : INF;

            int v11 = INF;
            if (x >= k) v11 = min(v11, ((x - k) + 1) / 2);
            int afterOp1 = (x + 1) / 2;
            if (afterOp1 >= k) v11 = min(v11, afterOp1 - k);

            for (int a = op1; a >= 0; a--) {
                for (int b = op2; b >= 0; b--) {
                    int best = (dp[a][b] < INF) ? dp[a][b] + v00 : INF;
                    if (a >= 1 && dp[a - 1][b] < INF && v10 < INF) {
                        best = min(best, dp[a - 1][b] + v10);
                    }
                    if (b >= 1 && dp[a][b - 1] < INF && v01 < INF) {
                        best = min(best, dp[a][b - 1] + v01);
                    }
                    if (a >= 1 && b >= 1 && dp[a - 1][b - 1] < INF && v11 < INF) {
                        best = min(best, dp[a - 1][b - 1] + v11);
                    }
                    dp[a][b] = best;
                }
            }
        }

        int result = INF;
        for (int a = 0; a <= op1; a++) {
            for (int b = 0; b <= op2; b++) {
                result = min(result, dp[a][b]);
            }
        }
        return result;
    }
};
