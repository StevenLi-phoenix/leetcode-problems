// @leetcode id=97 questionId=97 slug=interleaving-string lang=cpp site=leetcode.com title="Interleaving String"
class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        int n = s1.size(), m = s2.size();
        if (n + m != (int)s3.size()) return false;

        vector<char> dp(m + 1, 0);
        dp[0] = 1;
        for (int j = 1; j <= m; j++) dp[j] = dp[j - 1] && (s2[j - 1] == s3[j - 1]);

        for (int i = 1; i <= n; i++) {
            dp[0] = dp[0] && (s1[i - 1] == s3[i - 1]);
            for (int j = 1; j <= m; j++) {
                bool fromS1 = dp[j] && (s1[i - 1] == s3[i + j - 1]);
                bool fromS2 = dp[j - 1] && (s2[j - 1] == s3[i + j - 1]);
                dp[j] = fromS1 || fromS2;
            }
        }
        return dp[m];
    }
};
