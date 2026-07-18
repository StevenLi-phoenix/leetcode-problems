// @leetcode id=3563 questionId=3867 slug=lexicographically-smallest-string-after-adjacent-removals lang=cpp site=leetcode.com title="Lexicographically Smallest String After Adjacent Removals"
class Solution {
public:
    bool isAdjConsecutive(char a, char b) {
        int diff = abs(a - b);
        return diff == 1 || diff == 25;
    }

    string lexicographicallySmallestString(string s) {
        int n = s.size();
        vector<vector<bool>> canEmpty(n + 1, vector<bool>(n + 1, false));
        for (int i = 0; i <= n; i++) canEmpty[i][i] = true;

        for (int len = 2; len <= n; len += 2) {
            for (int i = 0; i + len <= n; i++) {
                int j = i + len;
                for (int p = i + 1; p < j; p += 2) {
                    if (isAdjConsecutive(s[i], s[p]) && canEmpty[i + 1][p] && canEmpty[p + 1][j]) {
                        canEmpty[i][j] = true;
                        break;
                    }
                }
            }
        }

        vector<string> dp(n + 1);
        dp[n] = "";

        for (int i = n - 1; i >= 0; i--) {
            string best = string(1, s[i]) + dp[i + 1];
            for (int j = i + 2; j <= n; j += 2) {
                if (canEmpty[i][j] && dp[j] < best) {
                    best = dp[j];
                }
            }
            dp[i] = best;
        }

        return dp[0];
    }
};
