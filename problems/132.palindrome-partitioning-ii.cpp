// @leetcode id=132 questionId=132 slug=palindrome-partitioning-ii lang=cpp site=leetcode.com title="Palindrome Partitioning II"
class Solution {
public:
    int minCut(string s) {
        int n = s.size();
        vector<vector<bool>> isPal(n, vector<bool>(n, false));
        for (int i = 0; i < n; i++) isPal[i][i] = true;
        for (int len = 2; len <= n; len++) {
            for (int i = 0; i + len - 1 < n; i++) {
                int j = i + len - 1;
                if (s[i] == s[j] && (len == 2 || isPal[i + 1][j - 1])) isPal[i][j] = true;
            }
        }

        vector<int> dp(n + 1, INT_MAX);
        dp[0] = -1;
        for (int j = 1; j <= n; j++) {
            for (int i = 0; i < j; i++) {
                if (isPal[i][j - 1] && dp[i] != INT_MAX) {
                    dp[j] = min(dp[j], dp[i] + 1);
                }
            }
        }

        return dp[n];
    }
};
