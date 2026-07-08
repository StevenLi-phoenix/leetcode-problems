// @leetcode id=69 questionId=69 slug=sqrtx lang=cpp site=leetcode.com title="Sqrt(x)"
class Solution {
public:
    int mySqrt(int x) {
        long long lo = 0, hi = x;
        while (lo < hi) {
            long long mid = lo + (hi - lo + 1) / 2;
            if (mid * mid <= x) lo = mid;
            else hi = mid - 1;
        }
        return (int)lo;
    }
};
