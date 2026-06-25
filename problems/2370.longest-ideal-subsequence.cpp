// @leetcode id=2370 questionId=2444 slug=longest-ideal-subsequence lang=cpp site=leetcode.com title="Longest Ideal Subsequence"
class Solution {
public:
    int longestIdealString(string s, int k) {
        // dp[c] = length of longest ideal subsequence ending with char c
        vector<int> dp(26, 0);
        int ans = 0;
        for (char c : s) {
            int v = c - 'a';
            int best = 0;
            for (int j = max(0, v - k); j <= min(25, v + k); j++) {
                best = max(best, dp[j]);
            }
            dp[v] = best + 1;
            ans = max(ans, dp[v]);
        }
        return ans;
    }
};
