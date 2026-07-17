// @leetcode id=3906 questionId=4124 slug=count-good-integers-on-a-grid-path lang=cpp site=leetcode.com title="Count Good Integers on a Grid Path"
class Solution {
public:
    static const int LEN = 16;
    bool isPathPos[LEN];
    string bound;
    // memo[pos][tight][lastDigit+1]
    long long memo[LEN + 1][2][11];
    bool computed[LEN + 1][2][11];

    long long dp(int pos, bool tight, int lastDigit) {
        if (pos == LEN) return 1;
        if (computed[pos][tight][lastDigit + 1]) return memo[pos][tight][lastDigit + 1];
        computed[pos][tight][lastDigit + 1] = true;

        int maxDigit = tight ? (bound[pos] - '0') : 9;
        long long total = 0;

        for (int d = 0; d <= maxDigit; d++) {
            int newLast = lastDigit;
            if (isPathPos[pos]) {
                if (lastDigit != -1 && d < lastDigit) continue;
                newLast = d;
            }
            bool newTight = tight && (d == maxDigit);
            total += dp(pos + 1, newTight, newLast);
        }

        memo[pos][tight][lastDigit + 1] = total;
        return total;
    }

    long long countUpTo(long long x) {
        if (x < 0) return 0;
        string s = to_string(x);
        while ((int)s.size() < LEN) s = "0" + s;
        bound = s;
        memset(computed, 0, sizeof(computed));
        return dp(0, true, -1);
    }

    long long countGoodIntegersOnPath(long long l, long long r, string directions) {
        memset(isPathPos, false, sizeof(isPathPos));
        int row = 0, col = 0;
        isPathPos[row * 4 + col] = true;
        for (char c : directions) {
            if (c == 'D') row++;
            else col++;
            isPathPos[row * 4 + col] = true;
        }

        return countUpTo(r) - countUpTo(l - 1);
    }
};
