// @leetcode id=1092 questionId=1170 slug=shortest-common-supersequence lang=cpp site=leetcode.com title="Shortest Common Supersequence "
class Solution {
public:
    string shortestCommonSupersequence(string str1, string str2) {
        int m = str1.size(), n = str2.size();
        vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));
        for (int i = 1; i <= m; i++)
            for (int j = 1; j <= n; j++)
                dp[i][j] = (str1[i - 1] == str2[j - 1])
                    ? dp[i - 1][j - 1] + 1
                    : max(dp[i - 1][j], dp[i][j - 1]);

        // Walk back through the LCS DP table: whenever characters match,
        // take one (part of the LCS, so only needed once); otherwise take
        // whichever string's remaining character came from the larger DP
        // value (the path the LCS actually took).
        string result;
        int i = m, j = n;
        while (i > 0 && j > 0) {
            if (str1[i - 1] == str2[j - 1]) {
                result += str1[i - 1];
                i--; j--;
            } else if (dp[i - 1][j] >= dp[i][j - 1]) {
                result += str1[i - 1];
                i--;
            } else {
                result += str2[j - 1];
                j--;
            }
        }
        while (i > 0) { result += str1[i - 1]; i--; }
        while (j > 0) { result += str2[j - 1]; j--; }

        reverse(result.begin(), result.end());
        return result;
    }
};
