// @leetcode id=1278 questionId=1403 slug=palindrome-partitioning-iii lang=cpp site=leetcode.com title="Palindrome Partitioning III"
class Solution {
public:
    int palindromePartition(string s, int k) {
        int n = s.size();
        // cost[i][j] = min changes to make s[i..j] a palindrome.
        vector<vector<int>> cost(n, vector<int>(n, 0));
        for (int len = 2; len <= n; len++) {
            for (int i = 0; i + len - 1 < n; i++) {
                int j = i + len - 1;
                cost[i][j] = cost[i + 1][j - 1] + (s[i] != s[j] ? 1 : 0);
            }
        }

        const int INF = INT_MAX / 2;
        // dp[i][p] = min cost to split s[0..i) into p palindromic parts.
        vector<vector<int>> dp(n + 1, vector<int>(k + 1, INF));
        dp[0][0] = 0;
        for (int i = 1; i <= n; i++) {
            for (int p = 1; p <= min(i, k); p++) {
                for (int j = p - 1; j < i; j++) {
                    if (dp[j][p - 1] == INF) continue;
                    dp[i][p] = min(dp[i][p], dp[j][p - 1] + cost[j][i - 1]);
                }
            }
        }
        return dp[n][k];
    }
};
