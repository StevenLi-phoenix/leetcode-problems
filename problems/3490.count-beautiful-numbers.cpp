// @leetcode id=3490 questionId=3801 slug=count-beautiful-numbers lang=cpp site=leetcode.com title="Count Beautiful Numbers"
class Solution {
public:
    string digits;
    int len, curS;
    long long memo[10][82][82][2];
    int memoVersion[10][82][82][2];
    int version;

    long long dp(int pos, int sumSoFar, int productMod, bool tight, bool started) {
        if (pos == len) return (started && sumSoFar == curS && productMod == 0) ? 1 : 0;
        if (!tight && memoVersion[pos][sumSoFar][productMod][started] == version) {
            return memo[pos][sumSoFar][productMod][started];
        }
        int limit = tight ? (digits[pos] - '0') : 9;
        long long res = 0;
        for (int d = 0; d <= limit; d++) {
            bool nstarted = started || d > 0;
            int nsum = sumSoFar + (nstarted ? d : 0);
            if (nsum > curS) continue;
            int nprod;
            if (!nstarted) nprod = 0;
            else if (started) nprod = (int)((long long)productMod * d % curS);
            else nprod = d % curS;
            bool ntight = tight && (d == limit);
            res += dp(pos + 1, nsum, nprod, ntight, nstarted);
        }
        if (!tight) {
            memo[pos][sumSoFar][productMod][started] = res;
            memoVersion[pos][sumSoFar][productMod][started] = version;
        }
        return res;
    }

    // Counts beautiful numbers in [1, N] by running a digit DP once per
    // candidate digit-sum s (1..81): a number is beautiful for sum s if its
    // digit sum equals s and its digit product mod s is 0.
    long long countUpTo(long long N) {
        if (N <= 0) return 0;
        digits = to_string(N);
        len = digits.size();
        long long total = 0;

        for (int s = 1; s <= 81; s++) {
            curS = s;
            version++;
            total += dp(0, 0, 0, true, false);
        }
        return total;
    }

    int beautifulNumbers(int l, int r) {
        version = 0;
        memset(memoVersion, -1, sizeof(memoVersion));
        return (int)(countUpTo(r) - countUpTo(l - 1));
    }
};
