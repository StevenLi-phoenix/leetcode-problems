// @leetcode id=2320 questionId=2397 slug=count-number-of-ways-to-place-houses lang=cpp site=leetcode.com title="Count Number of Ways to Place Houses"
class Solution {
public:
    int countHousePlacements(int n) {
        const long long MOD = 1e9 + 7;
        long long a = 1, b = 2; // ways for 0 plots, 1 plot
        for (int i = 2; i <= n; i++) {
            long long c = (a + b) % MOD;
            a = b;
            b = c;
        }
        return (int)((b * b) % MOD);
    }
};
