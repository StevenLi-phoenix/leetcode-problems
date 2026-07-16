// @leetcode id=2550 questionId=2680 slug=count-collisions-of-monkeys-on-a-polygon lang=cpp site=leetcode.com title="Count Collisions of Monkeys on a Polygon"
class Solution {
public:
    long long power(long long base, long long exp, long long mod) {
        long long result = 1;
        base %= mod;
        while (exp > 0) {
            if (exp & 1) result = (result * base) % mod;
            base = (base * base) % mod;
            exp >>= 1;
        }
        return result;
    }

    int monkeyMove(int n) {
        const long long MOD = 1e9 + 7;
        long long total = power(2, n, MOD);
        long long result = ((total - 2) % MOD + MOD) % MOD;
        return (int)result;
    }
};
