// @leetcode id=2827 questionId=3017 slug=number-of-beautiful-integers-in-the-range lang=cpp site=leetcode.com title="Number of Beautiful Integers in the Range"
class Solution {
public:
    string digits;
    int K;
    // memo[pos][diffOffset][modVal][started]
    long long memo[11][23][20][2];
    bool computed[11][23][20][2];

    long long dp(int pos, int diffOffset, int modVal, bool tight, bool started) {
        if (pos == (int)digits.size()) {
            return (started && diffOffset == 11 && modVal == 0) ? 1 : 0;
        }
        if (!tight && computed[pos][diffOffset][modVal][started]) {
            return memo[pos][diffOffset][modVal][started];
        }

        int maxDigit = tight ? (digits[pos] - '0') : 9;
        long long total = 0;

        for (int d = 0; d <= maxDigit; d++) {
            bool newStarted = started || d != 0;
            int newDiffOffset = diffOffset;
            int newModVal = modVal;
            if (newStarted) {
                if (!started && d == 0) {
                    // unreachable, kept for clarity
                }
                if (d % 2 == 0) newDiffOffset += 1; else newDiffOffset -= 1;
                newModVal = (modVal * 10 + d) % K;
            }
            bool newTight = tight && (d == maxDigit);
            total += dp(pos + 1, newDiffOffset, newModVal, newTight, newStarted);
        }

        if (!tight) {
            computed[pos][diffOffset][modVal][started] = true;
            memo[pos][diffOffset][modVal][started] = total;
        }
        return total;
    }

    long long countUpTo(long long x) {
        if (x <= 0) return 0;
        digits = to_string(x);
        memset(computed, 0, sizeof(computed));
        return dp(0, 11, 0, true, false);
    }

    int numberOfBeautifulIntegers(int low, int high, int k) {
        K = k;
        return (int)(countUpTo(high) - countUpTo(low - 1));
    }
};
