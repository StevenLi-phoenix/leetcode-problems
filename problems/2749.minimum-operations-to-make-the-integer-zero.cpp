// @leetcode id=2749 questionId=2837 slug=minimum-operations-to-make-the-integer-zero lang=cpp site=leetcode.com title="Minimum Operations to Make the Integer Zero"
class Solution {
public:
    int makeTheIntegerZero(int num1, int num2) {
        // After k operations, num1 - k*num2 must equal a sum of k powers of
        // two (repeats allowed), which is possible iff the target is
        // reachable: popcount(target) <= k <= target (each term >= 1, and
        // extra budget can always be split by breaking a power of 2 in
        // half into two smaller ones).
        for (long long k = 1; k <= 60; k++) {
            long long target = (long long)num1 - k * (long long)num2;
            if (target < k) continue;
            if (__builtin_popcountll((unsigned long long)target) <= k) return (int)k;
        }
        return -1;
    }
};
