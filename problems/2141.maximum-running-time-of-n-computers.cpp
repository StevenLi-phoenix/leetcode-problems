// @leetcode id=2141 questionId=2263 slug=maximum-running-time-of-n-computers lang=cpp site=leetcode.com title="Maximum Running Time of N Computers"
class Solution {
public:
    long long maxRunTime(int n, vector<int>& batteries) {
        long long total = 0;
        for (int b : batteries) total += b;

        auto feasible = [&](long long t) {
            long long sumCapped = 0;
            for (int b : batteries) sumCapped += min((long long)b, t);
            return sumCapped >= (long long)n * t;
        };

        long long lo = 0, hi = total / n;
        while (lo < hi) {
            long long mid = lo + (hi - lo + 1) / 2;
            if (feasible(mid)) lo = mid;
            else hi = mid - 1;
        }

        return lo;
    }
};
