// @leetcode id=2929 questionId=3201 slug=distribute-candies-among-children-ii lang=cpp site=leetcode.com title="Distribute Candies Among Children II"
class Solution {
public:
    long long distributeCandies(int n, int limit) {
        auto f = [](long long x) -> long long {
            if (x < 0) return 0;
            return (x + 2) * (x + 1) / 2;
        };

        long long L1 = limit + 1;
        return f(n) - 3 * f(n - L1) + 3 * f(n - 2 * L1) - f(n - 3 * L1);
    }
};
