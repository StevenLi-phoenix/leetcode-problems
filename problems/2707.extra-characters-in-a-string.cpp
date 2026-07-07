// @leetcode id=2707 questionId=2755 slug=extra-characters-in-a-string lang=cpp site=leetcode.com title="Extra Characters in a String"
class Solution {
public:
    int minExtraChar(string s, vector<string>& dictionary) {
        int n = s.size();
        unordered_set<string> dict(dictionary.begin(), dictionary.end());

        vector<int> dp(n + 1, 0);
        for (int i = 1; i <= n; ++i) {
            dp[i] = dp[i - 1] + 1; // treat s[i-1] as extra
            for (int j = 0; j < i; ++j) {
                if (dict.count(s.substr(j, i - j))) {
                    dp[i] = min(dp[i], dp[j]);
                }
            }
        }
        return dp[n];
    }
};
