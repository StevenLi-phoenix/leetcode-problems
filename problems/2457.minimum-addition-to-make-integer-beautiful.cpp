// @leetcode id=2457 questionId=2544 slug=minimum-addition-to-make-integer-beautiful lang=cpp site=leetcode.com title="Minimum Addition to Make Integer Beautiful"
class Solution {
public:
    int digitSum(long long x) {
        int s = 0;
        while (x > 0) {
            s += x % 10;
            x /= 10;
        }
        return s;
    }

    long long makeIntegerBeautiful(long long n, int target) {
        long long p = 1;
        while (true) {
            long long rounded = ((n + p - 1) / p) * p;
            if (digitSum(rounded) <= target) return rounded - n;
            p *= 10;
        }
    }
};
