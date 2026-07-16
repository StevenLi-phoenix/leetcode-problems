// @leetcode id=1201 questionId=1307 slug=ugly-number-iii lang=cpp site=leetcode.com title="Ugly Number III"
class Solution {
public:
    int nthUglyNumber(int n, int a, int b, int c) {
        long long la = a, lb = b, lc = c;
        long long lab = lcm(la, lb);
        long long lac = lcm(la, lc);
        long long lbc = lcm(lb, lc);
        long long labc = lcm(lab, lc);

        long long lo = 1, hi = 2000000000LL;
        while (lo < hi) {
            long long mid = lo + (hi - lo) / 2;
            long long count = mid / la + mid / lb + mid / lc
                - mid / lab - mid / lac - mid / lbc
                + mid / labc;
            if (count >= n) hi = mid;
            else lo = mid + 1;
        }
        return (int)lo;
    }

private:
    long long gcd(long long x, long long y) {
        while (y) { x %= y; swap(x, y); }
        return x;
    }
    long long lcm(long long x, long long y) {
        long long g = gcd(x, y);
        long long result = x / g * y;
        if (result > 2000000000LL || result <= 0) return 2000000001LL;
        return result;
    }
};
