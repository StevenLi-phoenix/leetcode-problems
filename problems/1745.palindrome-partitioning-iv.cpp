// @leetcode id=1745 questionId=1871 slug=palindrome-partitioning-iv lang=cpp site=leetcode.com title="Palindrome Partitioning IV"
class Solution {
public:
    bool checkPartitioning(string s) {
        int n = s.size();
        // dp[i][j] = true if s[i..j] is palindrome
        vector<vector<bool>> dp(n, vector<bool>(n, false));
        for (int i = n-1; i >= 0; i--) {
            for (int j = i; j < n; j++) {
                if (s[i] == s[j] && (j - i <= 2 || dp[i+1][j-1])) {
                    dp[i][j] = true;
                }
            }
        }
        // Try all possible cuts
        for (int i = 0; i < n-2; i++) {
            for (int j = i+1; j < n-1; j++) {
                if (dp[0][i] && dp[i+1][j] && dp[j+1][n-1]) return true;
            }
        }
        return false;
    }
};
