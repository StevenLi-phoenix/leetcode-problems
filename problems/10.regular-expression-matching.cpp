// @leetcode id=10 questionId=10 slug=regular-expression-matching lang=cpp site=leetcode.com title="Regular Expression Matching"
class Solution {
public:
    bool isMatch(string s, string p) {
        int n = (int)s.size(), m = (int)p.size();
        vector<vector<bool>> dp(n + 1, vector<bool>(m + 1, false));
        dp[0][0] = true;

        // Patterns like a*, a*b*, a*b*c* can match empty string
        for (int j = 2; j <= m; j++) {
            if (p[j - 1] == '*') dp[0][j] = dp[0][j - 2];
        }

        auto matchChar = [&](char sc, char pc) {
            return pc == '.' || pc == sc;
        };

        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                if (p[j - 1] != '*') {
                    if (matchChar(s[i - 1], p[j - 1])) {
                        dp[i][j] = dp[i - 1][j - 1];
                    }
                } else {
                    // '*' uses preceding element p[j-2]
                    dp[i][j] = dp[i][j - 2]; // zero occurrences
                    if (matchChar(s[i - 1], p[j - 2])) {
                        dp[i][j] = dp[i][j] || dp[i - 1][j]; // one/more
                    }
                }
            }
        }
        return dp[n][m];
    }
};
