// @leetcode id=62 questionId=62 slug=unique-paths lang=cpp site=leetcode.com title="Unique Paths"
class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<long long> dp(n, 1);
        for (int r = 1; r < m; ++r) {
            for (int c = 1; c < n; ++c) {
                dp[c] += dp[c - 1];
            }
        }
        return (int)dp[n - 1];
    }
};
