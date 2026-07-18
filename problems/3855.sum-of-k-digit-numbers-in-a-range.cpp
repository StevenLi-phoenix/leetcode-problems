// @leetcode id=3855 questionId=4239 slug=sum-of-k-digit-numbers-in-a-range lang=cpp site=leetcode.com title="Sum of K-Digit Numbers in a Range"
class Solution {
public:
    static const long long MOD = 1000000007;

    long long modpow(long long base, long long exp, long long mod) {
        base %= mod;
        long long result = 1;
        while (exp > 0) {
            if (exp & 1) result = result * base % mod;
            base = base * base % mod;
            exp >>= 1;
        }
        return result;
    }

    int sumOfNumbers(int l, int r, int k) {
        long long n = r - l + 1;
        long long S = (long long)(l + r) * n / 2 % MOD;
        long long repunit = (modpow(10, k, MOD) - 1 + MOD) % MOD * modpow(9, MOD - 2, MOD) % MOD;
        long long ans = modpow(n, k - 1, MOD) * S % MOD * repunit % MOD;
        return (int)ans;
    }
};
