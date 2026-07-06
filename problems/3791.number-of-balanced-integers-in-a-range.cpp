// @leetcode id=3791 questionId=4095 slug=number-of-balanced-integers-in-a-range lang=cpp site=leetcode.com title="Number of Balanced Integers in a Range"
class Solution {
public:
    long long countBalanced(long long low, long long high) {
        return balancedUpTo(high) - balancedUpTo(low - 1);
    }

private:
    static const int OFFSET = 150;

    long long balancedUpTo(long long n) {
        if (n <= 0) return 0;
        string digits = to_string(n);
        int L = digits.size();
        int diffSpan = 2 * OFFSET + 1;
        int cntSpan = L + 1;

        vector<long long> memo((size_t)(L + 1) * diffSpan * cntSpan, -1);
        auto memoIndex = [&](int pos, int diff, int cnt) {
            return ((size_t)pos * diffSpan + (diff + OFFSET)) * cntSpan + cnt;
        };

        function<long long(int, int, bool, int)> dfs = [&](int pos, int diff, bool tight, int cnt) -> long long {
            if (pos == L) return (cnt >= 2 && diff == 0) ? 1 : 0;
            size_t idx = memoIndex(pos, diff, cnt);
            if (!tight && memo[idx] != -1) return memo[idx];

            int maxDigit = tight ? (digits[pos] - '0') : 9;
            long long total = 0;

            for (int d = 0; d <= maxDigit; ++d) {
                bool newTight = tight && (d == maxDigit);
                if (cnt == 0 && d == 0) {
                    total += dfs(pos + 1, diff, newTight, 0);
                } else {
                    int sign = (cnt % 2 == 0) ? 1 : -1;
                    total += dfs(pos + 1, diff + sign * d, newTight, cnt + 1);
                }
            }

            if (!tight) memo[idx] = total;
            return total;
        };

        return dfs(0, 0, true, 0);
    }
};
