// @leetcode id=372 questionId=372 slug=super-pow lang=cpp site=leetcode.com title="Super Pow"
class Solution {
public:
    int superPow(int a, vector<int>& b) {
        const int MOD = 1337;
        long long result = 1;
        long long base = a % MOD;

        // a^(d0 d1 ... dk) = ((a^d0)^10 * a^d1)^10 * ... — process digits left to right
        for (int digit : b) {
            result = power(result, 10, MOD) * power(base, digit, MOD) % MOD;
        }
        return (int)result;
    }

private:
    long long power(long long x, int e, int mod) {
        x %= mod;
        long long r = 1;
        while (e > 0) {
            if (e & 1) r = r * x % mod;
            x = x * x % mod;
            e >>= 1;
        }
        return r;
    }
};
