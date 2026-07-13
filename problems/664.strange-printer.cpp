// @leetcode id=664 questionId=664 slug=strange-printer lang=cpp site=leetcode.com title="Strange Printer"
class Solution {
public:
    int strangePrinter(string s) {
        // Collapse consecutive duplicate characters first (they cost the
        // same as a single occurrence, since one print pass covers them).
        string t;
        for (char c : s)
            if (t.empty() || t.back() != c) t += c;

        int n = t.size();
        if (n == 0) return 0;
        vector<vector<int>> dp(n, vector<int>(n, 0));
        for (int i = 0; i < n; i++) dp[i][i] = 1;

        for (int len = 2; len <= n; len++) {
            for (int i = 0; i + len - 1 < n; i++) {
                int j = i + len - 1;
                dp[i][j] = dp[i][j - 1] + 1; // print t[j] on its own
                for (int k = i; k < j; k++) {
                    if (t[k] == t[j]) {
                        int leftPart = dp[i][k];
                        int rightPart = (k + 1 <= j - 1) ? dp[k + 1][j - 1] : 0;
                        dp[i][j] = min(dp[i][j], leftPart + rightPart);
                    }
                }
            }
        }
        return dp[0][n - 1];
    }
};
