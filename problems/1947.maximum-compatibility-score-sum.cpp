// @leetcode id=1947 questionId=2078 slug=maximum-compatibility-score-sum lang=cpp site=leetcode.com title="Maximum Compatibility Score Sum"
class Solution {
public:
    int maxCompatibilitySum(vector<vector<int>>& students, vector<vector<int>>& mentors) {
        int m = students.size();
        int n = students[0].size();

        vector<vector<int>> score(m, vector<int>(m, 0));
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < m; j++) {
                int s = 0;
                for (int k = 0; k < n; k++) {
                    if (students[i][k] == mentors[j][k]) s++;
                }
                score[i][j] = s;
            }
        }

        vector<int> dp(1 << m, -1);
        dp[0] = 0;
        for (int mask = 0; mask < (1 << m); mask++) {
            if (dp[mask] < 0) continue;
            int i = __builtin_popcount(mask);
            if (i == m) continue;
            for (int j = 0; j < m; j++) {
                if (mask & (1 << j)) continue;
                int newMask = mask | (1 << j);
                dp[newMask] = max(dp[newMask], dp[mask] + score[i][j]);
            }
        }
        return dp[(1 << m) - 1];
    }
};
