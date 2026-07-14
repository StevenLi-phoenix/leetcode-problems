// @leetcode id=730 questionId=730 slug=count-different-palindromic-subsequences lang=cpp site=leetcode.com title="Count Different Palindromic Subsequences"
class Solution {
public:
    int countPalindromicSubsequences(string s) {
        const long long MOD = 1e9 + 7;
        int n = s.size();
        // next[i][c] = smallest index >= i with s[index]==c ('a'+c); n if none.
        // prev[i][c] = largest index <= i with s[index]==c; -1 if none.
        vector<array<int, 4>> nextOcc(n + 1), prevOcc(n);
        nextOcc[n].fill(n);
        for (int i = n - 1; i >= 0; i--) {
            nextOcc[i] = nextOcc[i + 1];
            nextOcc[i][s[i] - 'a'] = i;
        }
        for (int i = 0; i < n; i++) {
            prevOcc[i] = (i > 0) ? prevOcc[i - 1] : array<int, 4>{-1, -1, -1, -1};
            prevOcc[i][s[i] - 'a'] = i;
        }

        vector<vector<long long>> dp(n, vector<long long>(n, 0));
        for (int i = 0; i < n; i++) dp[i][i] = 1;

        for (int len = 2; len <= n; len++) {
            for (int i = 0; i + len - 1 < n; i++) {
                int j = i + len - 1;
                if (s[i] != s[j]) {
                    dp[i][j] = (dp[i + 1][j] + dp[i][j - 1] - dp[i + 1][j - 1] + MOD) % MOD;
                } else {
                    int c = s[i] - 'a';
                    int l = (i + 1 <= j - 1) ? nextOcc[i + 1][c] : n;
                    int r = (i + 1 <= j - 1) ? prevOcc[j - 1][c] : -1;
                    if (l > j - 1) { // no occurrence of c strictly inside
                        dp[i][j] = (2 * dp[i + 1][j - 1] + 2) % MOD;
                    } else if (l == r) { // exactly one occurrence inside
                        dp[i][j] = (2 * dp[i + 1][j - 1] + 1) % MOD;
                    } else {
                        dp[i][j] = (2 * dp[i + 1][j - 1] - dp[l + 1][r - 1] + MOD) % MOD;
                    }
                }
            }
        }
        return (int)dp[0][n - 1];
    }
};
