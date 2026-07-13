// @leetcode id=1416 questionId=1517 slug=restore-the-array lang=cpp site=leetcode.com title="Restore The Array"
class Solution {
public:
    int numberOfArrays(string s, int k) {
        const long long MOD = 1e9 + 7;
        int n = s.size();
        string kStr = to_string(k);
        int kLen = kStr.size();

        // dp[i] = ways to split the suffix s[i:]. Iterating forward from a
        // fixed start means a leading zero at s[i] invalidates every
        // length at once (unlike fixing the end and varying the start).
        vector<long long> dp(n + 1, 0);
        dp[n] = 1;

        for (int i = n - 1; i >= 0; i--) {
            if (s[i] == '0') continue;
            for (int len = 1; len <= min(n - i, kLen); len++) {
                if (len == kLen) {
                    string sub = s.substr(i, len);
                    if (sub > kStr) break;
                }
                dp[i] = (dp[i] + dp[i + len]) % MOD;
            }
        }
        return (int)dp[0];
    }
};
