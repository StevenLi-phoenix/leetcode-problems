// @leetcode id=3966 questionId=4310 slug=count-good-integers-in-a-range lang=cpp site=leetcode.com title="Count Good Integers in a Range"
class Solution {
public:
    string digits;
    int len, kk;
    long long memo[17][11];
    bool memoSet[17][11];

    long long dp(int pos, int prevDigit, bool tight, bool started) {
        if (pos == len) return 1;
        if (!tight && memoSet[pos][prevDigit]) return memo[pos][prevDigit];

        int limit = tight ? (digits[pos] - '0') : 9;
        long long res = 0;
        for (int d = 0; d <= limit; d++) {
            bool nstarted = started || d > 0;
            if (nstarted && started && abs(d - prevDigit) > kk) continue;
            int nprev = nstarted ? d : 10;
            bool ntight = tight && (d == limit);
            res += dp(pos + 1, nprev, ntight, nstarted);
        }
        if (!tight) { memo[pos][prevDigit] = res; memoSet[pos][prevDigit] = true; }
        return res;
    }

    long long countUpTo(long long n) {
        if (n < 0) return 0;
        digits = to_string(n);
        len = digits.size();
        memset(memoSet, false, sizeof(memoSet));
        return dp(0, 10, true, false);
    }

    long long goodIntegers(long long l, long long r, int k) {
        kk = k;
        return countUpTo(r) - countUpTo(l - 1);
    }
};
