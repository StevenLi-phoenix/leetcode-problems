// @leetcode id=467 questionId=467 slug=unique-substrings-in-wraparound-string lang=cpp site=leetcode.com title="Unique Substrings in Wraparound String"
class Solution {
public:
    int findSubstringInWraproundString(string s) {
        vector<int> dp(26, 0);
        int len = 1;

        for (int i = 0; i < (int)s.length(); i++) {
            if (i > 0 && (s[i] - s[i-1] + 26) % 26 == 1) {
                len++;
            } else {
                len = 1;
            }
            dp[s[i] - 'a'] = max(dp[s[i] - 'a'], len);
        }

        int result = 0;
        for (int i = 0; i < 26; i++) {
            result += dp[i];
        }
        return result;
    }
};
