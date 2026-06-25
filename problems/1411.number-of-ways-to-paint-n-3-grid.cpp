// @leetcode id=1411 questionId=1527 slug=number-of-ways-to-paint-n-3-grid lang=cpp site=leetcode.com title="Number of Ways to Paint N × 3 Grid"
class Solution {
public:
    int numOfWays(int n) {
        const long long MOD = 1000000007LL;

        // For row 1:
        long long a = 6; // ABA
        long long b = 6; // ABC

        for (int i = 2; i <= n; i++) {
            long long na = (3 * a + 2 * b) % MOD;
            long long nb = (2 * a + 2 * b) % MOD;
            a = na;
            b = nb;
        }

        return (int)((a + b) % MOD);
    }
};
