// @leetcode id=878 questionId=910 slug=nth-magical-number lang=cpp site=leetcode.com title="Nth Magical Number"
class Solution {
public:
    int nthMagicalNumber(int n, int a, int b) {
        const long long MOD = 1e9 + 7;
        long long g = gcd((long long)a, (long long)b);
        long long lcm = (long long)a / g * b;

        long long lo = 1, hi = (long long)n * min(a, b);
        while (lo < hi) {
            long long mid = lo + (hi - lo) / 2;
            long long count = mid / a + mid / b - mid / lcm;
            if (count >= n) hi = mid;
            else lo = mid + 1;
        }
        return (int)(lo % MOD);
    }
};
