// @leetcode id=1547 questionId=1669 slug=minimum-cost-to-cut-a-stick lang=cpp site=leetcode.com title="Minimum Cost to Cut a Stick"
class Solution {
public:
    int minCost(int n, vector<int>& cuts) {
        vector<int> points = cuts;
        points.push_back(0);
        points.push_back(n);
        sort(points.begin(), points.end());
        int m = points.size();

        vector<vector<int>> dp(m, vector<int>(m, 0));
        for (int len = 2; len < m; len++) {
            for (int i = 0; i + len < m; i++) {
                int j = i + len;
                int best = INT_MAX;
                for (int k = i + 1; k < j; k++) {
                    best = min(best, dp[i][k] + dp[k][j]);
                }
                dp[i][j] = best + (points[j] - points[i]);
            }
        }
        return dp[0][m - 1];
    }
};
