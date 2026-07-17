// @leetcode id=1312 questionId=1437 slug=minimum-insertion-steps-to-make-a-string-palindrome lang=cpp site=leetcode.com title="Minimum Insertion Steps to Make a String Palindrome"
class Solution {
public:
    int minInsertions(string s) {
        int n = s.size();
        string r = s;
        reverse(r.begin(), r.end());

        vector<vector<int>> dp(n + 1, vector<int>(n + 1, 0));
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                if (s[i - 1] == r[j - 1]) dp[i][j] = dp[i - 1][j - 1] + 1;
                else dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }

        return n - dp[n][n];
    }
};
