// @leetcode id=3871 questionId=4248 slug=count-commas-in-range-ii lang=cpp site=leetcode.com title="Count Commas in Range II"
class Solution {
public:
    long long countCommas(long long n) {
        long long total = 0;
        long long lo = 1;
        for (int d = 1; d <= 18 && lo <= n; d++) {
            long long hi = lo * 10 - 1;
            long long rangeHi = min(hi, n);
            long long count = rangeHi - lo + 1;
            long long commasPerNum = (d - 1) / 3;
            total += count * commasPerNum;
            lo = hi + 1;
        }
        return total;
    }
};
