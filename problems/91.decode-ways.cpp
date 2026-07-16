// @leetcode id=91 questionId=91 slug=decode-ways lang=cpp site=leetcode.com title="Decode Ways"
class Solution {
public:
    int numDecodings(string s) {
        int n = s.size();
        if (s[0] == '0') return 0;
        vector<long long> dp(n + 1, 0);
        dp[0] = 1;
        dp[1] = 1;
        for (int i = 2; i <= n; i++) {
            if (s[i - 1] != '0') dp[i] += dp[i - 1];
            int twoDigit = (s[i - 2] - '0') * 10 + (s[i - 1] - '0');
            if (twoDigit >= 10 && twoDigit <= 26) dp[i] += dp[i - 2];
        }
        return (int)dp[n];
    }
};
