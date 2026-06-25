// @leetcode id=1922 questionId=2050 slug=count-good-numbers lang=cpp site=leetcode.com title="Count Good Numbers"
class Solution {
public:
    const long long MOD = 1e9 + 7;
    
    long long power(long long base, long long exp, long long mod) {
        long long result = 1;
        base %= mod;
        while (exp > 0) {
            if (exp & 1) result = result * base % mod;
            base = base * base % mod;
            exp >>= 1;
        }
        return result;
    }
    
    int countGoodNumbers(long long n) {
        // Even positions: ceil(n/2) = (n+1)/2 positions, 5 choices each
        // Odd positions: floor(n/2) = n/2 positions, 4 choices each
        long long evenPositions = (n + 1) / 2;
        long long oddPositions = n / 2;
        
        long long result = power(5, evenPositions, MOD) * power(4, oddPositions, MOD) % MOD;
        return (int)result;
    }
};
