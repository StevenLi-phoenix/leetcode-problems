// @leetcode id=3316 questionId=3487 slug=find-maximum-removals-from-source-string lang=cpp site=leetcode.com title="Find Maximum Removals From Source String"
class Solution {
public:
    int maxRemovals(string source, string pattern, vector<int>& targetIndices) {
        int n = source.size(), m = pattern.size();
        vector<bool> isTarget(n, false);
        for (int idx : targetIndices) isTarget[idx] = true;

        const int INF = INT_MAX / 2;
        vector<vector<int>> dp(n + 1, vector<int>(m + 1, INF));
        dp[0][0] = 0;

        for (int i = 1; i <= n; i++) {
            dp[i][0] = 0;
            for (int j = 1; j <= m; j++) {
                dp[i][j] = dp[i - 1][j];
                if (source[i - 1] == pattern[j - 1] && dp[i - 1][j - 1] < INF) {
                    int cand = dp[i - 1][j - 1] + (isTarget[i - 1] ? 1 : 0);
                    dp[i][j] = min(dp[i][j], cand);
                }
            }
        }

        return (int)targetIndices.size() - dp[n][m];
    }
};
