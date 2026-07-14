// @leetcode id=3472 questionId=3786 slug=longest-palindromic-subsequence-after-at-most-k-operations lang=cpp site=leetcode.com title="Longest Palindromic Subsequence After at Most K Operations"
class Solution {
public:
    int longestPalindromicSubsequence(string s, int k) {
        int n = s.size();
        // dp[i][j][b] = longest palindromic subsequence of s[i..j] using at most b operations.
        vector<vector<vector<int>>> dp(n, vector<vector<int>>(n, vector<int>(k + 1, 0)));
        for (int i = 0; i < n; i++) {
            for (int b = 0; b <= k; b++) dp[i][i][b] = 1;
        }

        for (int len = 2; len <= n; len++) {
            for (int i = 0; i + len - 1 < n; i++) {
                int j = i + len - 1;
                int diff = abs(s[i] - s[j]);
                int cost = min(diff, 26 - diff);
                for (int b = 0; b <= k; b++) {
                    int best = 0;
                    if (i + 1 <= j) best = max(best, dp[i + 1][j][b]);
                    if (i <= j - 1) best = max(best, dp[i][j - 1][b]);
                    if (b >= cost) {
                        int inner = (i + 1 <= j - 1) ? dp[i + 1][j - 1][b - cost] : 0;
                        best = max(best, 2 + inner);
                    }
                    dp[i][j][b] = best;
                }
            }
        }
        return dp[0][n - 1][k];
    }
};
