// @leetcode id=1937 questionId=2067 slug=maximum-number-of-points-with-cost lang=cpp site=leetcode.com title="Maximum Number of Points with Cost"
class Solution {
public:
    long long maxPoints(vector<vector<int>>& points) {
        int m = points.size(), n = points[0].size();
        vector<long long> dp(n);
        for (int c = 0; c < n; c++) dp[c] = points[0][c];

        for (int r = 1; r < m; r++) {
            vector<long long> left(n), right(n), next(n);
            left[0] = dp[0];
            for (int c = 1; c < n; c++) left[c] = max(left[c - 1] - 1, dp[c]);
            right[n - 1] = dp[n - 1];
            for (int c = n - 2; c >= 0; c--) right[c] = max(right[c + 1] - 1, dp[c]);
            for (int c = 0; c < n; c++) next[c] = max(left[c], right[c]) + points[r][c];
            dp = next;
        }

        long long best = 0;
        for (long long v : dp) best = max(best, v);
        return best;
    }
};
