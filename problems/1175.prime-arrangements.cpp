// @leetcode id=1175 questionId=1279 slug=prime-arrangements lang=cpp site=leetcode.com title="Prime Arrangements"
class Solution {
public:
    bool isPrime(int x) {
        if (x < 2) return false;
        for (int i = 2; (long long)i * i <= x; i++) {
            if (x % i == 0) return false;
        }
        return true;
    }

    int numPrimeArrangements(int n) {
        const long long MOD = 1e9 + 7;
        int primeCount = 0;
        for (int i = 2; i <= n; i++) {
            if (isPrime(i)) primeCount++;
        }
        int nonPrimeCount = n - primeCount;

        long long result = 1;
        for (int i = 2; i <= primeCount; i++) result = result * i % MOD;
        for (int i = 2; i <= nonPrimeCount; i++) result = result * i % MOD;

        return (int)result;
    }
};
