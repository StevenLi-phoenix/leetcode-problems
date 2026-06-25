// @leetcode id=712 questionId=712 slug=minimum-ascii-delete-sum-for-two-strings lang=cpp site=leetcode.com title="Minimum ASCII Delete Sum for Two Strings"
class Solution {
public:
    int minimumDeleteSum(string s1, string s2) {
        int n = (int)s1.size(), m = (int)s2.size();
        vector<int> dp(m + 1, 0);

        // dp[m] = 0 already; build base for i = n (s1 empty): delete rest of s2
        for (int j = m - 1; j >= 0; --j) {
            dp[j] = dp[j + 1] + (int)s2[j];
        }

        // Fill rows from i = n-1 down to 0
        for (int i = n - 1; i >= 0; --i) {
            int diag = dp[m];                // old dp[i+1][m]
            dp[m] = dp[m] + (int)s1[i];      // dp[i][m]: delete rest of s1
            for (int j = m - 1; j >= 0; --j) {
                int old = dp[j];             // old dp[i+1][j]
                if (s1[i] == s2[j]) {
                    dp[j] = diag;            // dp[i][j] = dp[i+1][j+1]
                } else {
                    dp[j] = min((int)s1[i] + dp[j],      // delete s1[i] -> dp[i+1][j]
                                (int)s2[j] + dp[j + 1]); // delete s2[j] -> dp[i][j+1]
                }
                diag = old;                  // move diagonal for next j
            }
        }

        return dp[0];
    }
};
