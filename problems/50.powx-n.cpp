// @leetcode id=50 questionId=50 slug=powx-n lang=cpp site=leetcode.com title="Pow(x, n)"
class Solution {
public:
    double myPow(double x, int n) {
        long long e = n;
        bool negative = e < 0;
        if (negative) e = -e;

        double result = 1.0;
        double base = x;
        while (e > 0) {
            if (e & 1) result *= base;
            base *= base;
            e >>= 1;
        }
        return negative ? 1.0 / result : result;
    }
};
