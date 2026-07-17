// @leetcode id=793 questionId=809 slug=preimage-size-of-factorial-zeroes-function lang=cpp site=leetcode.com title="Preimage Size of Factorial Zeroes Function"
class Solution {
public:
    long long zeroes(long long x) {
        long long count = 0;
        for (long long p = 5; p <= x; p *= 5) count += x / p;
        return count;
    }

    int preimageSizeFZF(int k) {
        long long lo = 0, hi = 5LL * ((long long)k + 1);
        while (lo < hi) {
            long long mid = lo + (hi - lo) / 2;
            if (zeroes(mid) < k) lo = mid + 1;
            else hi = mid;
        }
        return zeroes(lo) == k ? 5 : 0;
    }
};
