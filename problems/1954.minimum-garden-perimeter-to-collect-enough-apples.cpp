// @leetcode id=1954 questionId=1295 slug=minimum-garden-perimeter-to-collect-enough-apples lang=cpp site=leetcode.com title="Minimum Garden Perimeter to Collect Enough Apples"
class Solution {
public:
    long long minimumPerimeter(long long neededApples) {
        auto apples = [](long long n) {
            return 2 * n * (n + 1) * (2 * n + 1);
        };

        long long lo = 1, hi = 100000;
        while (lo < hi) {
            long long mid = lo + (hi - lo) / 2;
            if (apples(mid) >= neededApples) hi = mid;
            else lo = mid + 1;
        }
        return lo * 8;
    }
};
