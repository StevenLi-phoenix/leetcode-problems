// @leetcode id=2513 questionId=2628 slug=minimize-the-maximum-of-two-arrays lang=cpp site=leetcode.com title="Minimize the Maximum of Two Arrays"
class Solution {
public:
    int minimizeSet(int divisor1, int divisor2, int uniqueCnt1, int uniqueCnt2) {
        long long l = lcm((long long)divisor1, (long long)divisor2);

        auto feasible = [&](long long m) {
            long long avail1 = m - m / divisor1;
            long long avail2 = m - m / divisor2;
            long long availShared = m - m / l;
            return avail1 >= uniqueCnt1 && avail2 >= uniqueCnt2 &&
                   availShared >= (long long)uniqueCnt1 + uniqueCnt2;
        };

        long long lo = 1, hi = 4e9;
        while (lo < hi) {
            long long mid = lo + (hi - lo) / 2;
            if (feasible(mid)) hi = mid;
            else lo = mid + 1;
        }
        return (int)lo;
    }
};
