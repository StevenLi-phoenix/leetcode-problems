// @leetcode id=2430 questionId=2510 slug=maximum-deletions-on-a-string lang=cpp site=leetcode.com title="Maximum Deletions on a String"
class Solution {
public:
    int deleteString(string s) {
        int n = s.size();
        vector<vector<int>> lcp(n + 1, vector<int>(n + 1, 0));
        for (int i = n - 1; i >= 0; i--) {
            for (int j = n - 1; j >= 0; j--) {
                if (s[i] == s[j]) lcp[i][j] = lcp[i + 1][j + 1] + 1;
            }
        }

        vector<int> dp(n + 1, 0);
        for (int i = n - 1; i >= 0; i--) {
            int best = 1; // always allowed: delete the entire remaining string
            int maxLen = (n - i) / 2;
            for (int len = 1; len <= maxLen; len++) {
                if (lcp[i][i + len] >= len) {
                    best = max(best, 1 + dp[i + len]);
                }
            }
            dp[i] = best;
        }
        return dp[0];
    }
};
