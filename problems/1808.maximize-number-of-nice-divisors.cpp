// @leetcode id=1808 questionId=1936 slug=maximize-number-of-nice-divisors lang=cpp site=leetcode.com title="Maximize Number of Nice Divisors"
class Solution {
public:
    long long modpow(long long base, long long exp, long long mod) {
        long long result = 1;
        base %= mod;
        while (exp > 0) {
            if (exp & 1) result = result * base % mod;
            base = base * base % mod;
            exp >>= 1;
        }
        return result;
    }

    int maxNiceDivisors(int primeFactors) {
        const long long MOD = 1e9 + 7;
        if (primeFactors <= 3) return primeFactors;

        int q = primeFactors / 3;
        int r = primeFactors % 3;
        long long result;
        if (r == 0) result = modpow(3, q, MOD);
        else if (r == 1) result = modpow(3, q - 1, MOD) * 4 % MOD;
        else result = modpow(3, q, MOD) * 2 % MOD;
        return (int)result;
    }
};
