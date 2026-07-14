// @leetcode id=1039 questionId=1111 slug=minimum-score-triangulation-of-polygon lang=cpp site=leetcode.com title="Minimum Score Triangulation of Polygon"
class Solution {
public:
    int minScoreTriangulation(vector<int>& values) {
        int n = values.size();
        vector<vector<int>> dp(n, vector<int>(n, 0));

        for (int len = 2; len < n; len++) {
            for (int i = 0; i + len < n; i++) {
                int j = i + len;
                int best = INT_MAX;
                for (int k = i + 1; k < j; k++) {
                    int score = dp[i][k] + dp[k][j] + values[i] * values[k] * values[j];
                    best = min(best, score);
                }
                dp[i][j] = best;
            }
        }
        return dp[0][n - 1];
    }
};
