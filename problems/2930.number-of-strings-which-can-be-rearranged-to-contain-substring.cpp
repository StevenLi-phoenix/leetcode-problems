// @leetcode id=2930 questionId=3200 slug=number-of-strings-which-can-be-rearranged-to-contain-substring lang=cpp site=leetcode.com title="Number of Strings Which Can Be Rearranged to Contain Substring"
class Solution {
public:
    int stringCount(int n) {
        const long long MOD = 1e9 + 7;
        
        // fast modular exponentiation
        auto powmod = [&](long long base, long long exp, long long mod) -> long long {
            long long result = 1;
            base %= mod;
            while (exp > 0) {
                if (exp & 1) result = result * base % mod;
                base = base * base % mod;
                exp >>= 1;
            }
            return result;
        };
        
        long long p26 = powmod(26, n, MOD);
        long long p25 = powmod(25, n, MOD);
        long long p25n1 = (n >= 1) ? powmod(25, n - 1, MOD) : 1;
        long long p24 = powmod(24, n, MOD);
        long long p24n1 = (n >= 1) ? powmod(24, n - 1, MOD) : 1;
        long long p23 = powmod(23, n, MOD);
        long long p23n1 = (n >= 1) ? powmod(23, n - 1, MOD) : 1;
        
        // Good = 26^n - 3*25^n - n*25^(n-1) + 3*24^n + 2*n*24^(n-1) - 23^n - n*23^(n-1)
        long long ans = p26;
        ans = (ans - 3 * p25 % MOD + MOD) % MOD;
        ans = (ans - (long long)n % MOD * p25n1 % MOD + MOD) % MOD;
        ans = (ans + 3 * p24) % MOD;
        ans = (ans + 2LL * n % MOD * p24n1) % MOD;
        ans = (ans - p23 + MOD) % MOD;
        ans = (ans - (long long)n % MOD * p23n1 % MOD + MOD) % MOD;
        
        return (int)ans;
    }
};
