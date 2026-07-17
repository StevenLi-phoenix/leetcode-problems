// @leetcode id=3426 questionId=3739 slug=manhattan-distances-of-all-arrangements-of-pieces lang=cpp site=leetcode.com title="Manhattan Distances of All Arrangements of Pieces"
class Solution {
public:
    static const long long MOD = 1000000007;

    long long power(long long base, long long exp, long long mod) {
        base %= mod;
        long long result = 1;
        while (exp > 0) {
            if (exp & 1) result = result * base % mod;
            base = base * base % mod;
            exp >>= 1;
        }
        return result;
    }

    int distanceSum(int m, int n, int k) {
        int total = m * n;

        vector<long long> fact(total + 1), invFact(total + 1);
        fact[0] = 1;
        for (int i = 1; i <= total; i++) fact[i] = fact[i-1] * i % MOD;
        invFact[total] = power(fact[total], MOD - 2, MOD);
        for (int i = total; i > 0; i--) invFact[i-1] = invFact[i] * i % MOD;

        auto C = [&](long long a, long long b) -> long long {
            if (b < 0 || b > a || a < 0) return 0;
            return fact[a] * invFact[b] % MOD * invFact[a-b] % MOD;
        };

        auto sumDiffs = [&](long long len) -> long long {
            long long s = 0;
            for (long long d = 1; d < len; d++) s = (s + d % MOD * ((len - d) % MOD)) % MOD;
            return s;
        };

        long long Sm = sumDiffs(m);
        long long Sn = sumDiffs(n);

        long long totalCellPairDist = ((long long)n % MOD * n % MOD * Sm % MOD +
                                        (long long)m % MOD * m % MOD * Sn % MOD) % MOD;

        long long comb = C(total - 2, k - 2);

        long long answer = totalCellPairDist * comb % MOD;
        return (int)answer;
    }
};
