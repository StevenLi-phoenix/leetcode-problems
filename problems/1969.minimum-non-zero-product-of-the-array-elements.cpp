// @leetcode id=1969 questionId=2100 slug=minimum-non-zero-product-of-the-array-elements lang=cpp site=leetcode.com title="Minimum Non-Zero Product of the Array Elements"
class Solution {
public:
    long long power(long long base, long long exp, long long mod) {
        base %= mod;
        if (base < 0) base += mod;
        long long result = 1;
        while (exp > 0) {
            if (exp & 1) result = (result * base) % mod;
            base = (base * base) % mod;
            exp >>= 1;
        }
        return result;
    }

    int minNonZeroProduct(int p) {
        const long long MOD = 1e9 + 7;
        long long twoP = power(2, p, MOD);
        long long maxVal = (twoP - 1 + MOD) % MOD;
        long long base = (twoP - 2 + MOD) % MOD;
        long long exponent = (1LL << (p - 1)) - 1;
        long long result = (power(base, exponent, MOD) * maxVal) % MOD;
        return (int)result;
    }
};
