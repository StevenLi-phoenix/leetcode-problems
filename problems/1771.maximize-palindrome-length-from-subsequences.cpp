// @leetcode id=1771 questionId=1897 slug=maximize-palindrome-length-from-subsequences lang=cpp site=leetcode.com title="Maximize Palindrome Length From Subsequences"
class Solution {
public:
    int longestPalindrome(string word1, string word2) {
        string s = word1 + word2;
        int n = s.size();
        int len1 = word1.size();

        vector<vector<int>> dp(n, vector<int>(n, 0));
        for (int i = 0; i < n; i++) dp[i][i] = 1;

        for (int length = 2; length <= n; length++) {
            for (int i = 0; i + length - 1 < n; i++) {
                int j = i + length - 1;
                if (s[i] == s[j]) {
                    dp[i][j] = (length == 2 ? 2 : dp[i + 1][j - 1] + 2);
                } else {
                    dp[i][j] = max(dp[i + 1][j], dp[i][j - 1]);
                }
            }
        }

        int best = 0;
        for (int i = 0; i < len1; i++) {
            for (int j = len1; j < n; j++) {
                if (s[i] == s[j]) best = max(best, dp[i][j]);
            }
        }

        return best;
    }
};
