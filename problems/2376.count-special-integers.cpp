// @leetcode id=2376 questionId=2457 slug=count-special-integers lang=cpp site=leetcode.com title="Count Special Integers"
class Solution {
public:
    int countSpecialNumbers(int n) {
        string digits = to_string(n);
        int len = digits.size();

        auto perm = [](int available, int choose) {
            long long res = 1;
            for (int i = 0; i < choose; i++) res *= (available - i);
            return res;
        };

        long long total = 0;
        // Numbers with fewer digits than n: first digit 1-9, rest distinct
        // from the remaining 9 digits.
        for (int d = 1; d < len; d++) total += 9 * perm(9, d - 1);

        // Numbers with exactly len digits, built digit-by-digit tight to n's prefix.
        bool used[10] = {};
        bool tight = true;
        for (int i = 0; i < len && tight; i++) {
            int digit = digits[i] - '0';
            int startDigit = (i == 0) ? 1 : 0;
            for (int d = startDigit; d < digit; d++) {
                if (used[d]) continue;
                int usedCount = 0;
                for (int u = 0; u < 10; u++) usedCount += used[u];
                total += perm(10 - usedCount - 1, len - i - 1);
            }
            if (used[digit]) { tight = false; break; }
            used[digit] = true;
        }
        if (tight) total += 1; // n itself has all distinct digits

        return (int)total;
    }
};
