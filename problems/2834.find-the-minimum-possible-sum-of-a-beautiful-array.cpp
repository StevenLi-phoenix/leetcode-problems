// @leetcode id=2834 questionId=3026 slug=find-the-minimum-possible-sum-of-a-beautiful-array lang=cpp site=leetcode.com title="Find the Minimum Possible Sum of a Beautiful Array"
class Solution {
public:
    long long minimumPossibleSum(int n, int target) {
        const long long MOD = 1e9 + 7;
        long long half = target / 2;
        long long take = min((long long)n, half);
        long long sum = take % MOD * ((take + 1) % MOD) % MOD * 500000004 % MOD;
        
        long long remaining = n - take;
        if (remaining > 0) {
            long long r = remaining % MOD;
            long long t = (long long)target % MOD;
            long long s1 = r * t % MOD;
            long long s2 = r * ((remaining - 1) % MOD) % MOD * 500000004 % MOD;
            sum = (sum + s1 + s2) % MOD;
        }
        
        return sum;
    }
};
