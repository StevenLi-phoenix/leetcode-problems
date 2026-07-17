// @leetcode id=639 questionId=639 slug=decode-ways-ii lang=cpp site=leetcode.com title="Decode Ways II"
class Solution {
public:
    const long long MOD = 1e9 + 7;

    long long ways1(char c) {
        if (c == '*') return 9;
        if (c == '0') return 0;
        return 1;
    }

    long long ways2(char a, char b) {
        if (a == '*' && b == '*') return 15; // 11-19, 21-26
        if (a == '*') {
            long long cnt = 1; // a=1, any b valid (10-19)
            if (b <= '6') cnt++; // a=2
            return cnt;
        }
        if (b == '*') {
            if (a == '1') return 9;
            if (a == '2') return 6;
            return 0;
        }
        int num = (a - '0') * 10 + (b - '0');
        return (a != '0' && num >= 10 && num <= 26) ? 1 : 0;
    }

    int numDecodings(string s) {
        int n = s.size();
        long long prev2 = 1; // dp[0]
        long long prev1 = ways1(s[0]); // dp[1]

        for (int i = 2; i <= n; i++) {
            long long cur = (prev1 * ways1(s[i - 1]) + prev2 * ways2(s[i - 2], s[i - 1])) % MOD;
            prev2 = prev1;
            prev1 = cur;
        }

        return (int)prev1;
    }
};
