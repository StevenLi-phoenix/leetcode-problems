// @leetcode id=2472 questionId=2559 slug=maximum-number-of-non-overlapping-palindrome-substrings lang=cpp site=leetcode.com title="Maximum Number of Non-overlapping Palindrome Substrings"
class Solution {
public:
    int maxPalindromes(string s, int k) {
        // Any palindrome longer than the minimum useful length contains a
        // palindrome of length k or k+1 sharing the same start (trim equal
        // amounts off both ends), so for interval-scheduling purposes it
        // suffices to only ever try taking the shortest valid palindrome
        // (length k or k+1) starting at each position.
        int n = s.size();
        vector<vector<char>> isPal(n, vector<char>(n, 0));
        for (int i = n - 1; i >= 0; i--) {
            isPal[i][i] = 1;
            for (int j = i + 1; j < n; j++) {
                if (s[i] == s[j] && (j - i < 2 || isPal[i + 1][j - 1])) isPal[i][j] = 1;
            }
        }

        vector<int> dp(n + 1, 0);
        for (int i = 0; i < n; i++) {
            dp[i + 1] = max(dp[i + 1], dp[i]);
            if (i + k <= n && isPal[i][i + k - 1]) dp[i + k] = max(dp[i + k], dp[i] + 1);
            if (i + k + 1 <= n && isPal[i][i + k]) dp[i + k + 1] = max(dp[i + k + 1], dp[i] + 1);
        }
        return dp[n];
    }
};
