// @leetcode id=2594 questionId=2665 slug=minimum-time-to-repair-cars lang=cpp site=leetcode.com title="Minimum Time to Repair Cars"
class Solution {
public:
    long long repairCars(vector<int>& ranks, int cars) {
        int maxRank = *max_element(ranks.begin(), ranks.end());
        long long lo = 1, hi = (long long)maxRank * cars * cars;

        auto feasible = [&](long long time) -> bool {
            long long total = 0;
            for (int r : ranks) {
                long long cnt = (long long)sqrt((double)time / r);
                while (cnt * cnt * r > time) cnt--;
                while ((cnt + 1) * (cnt + 1) * r <= time) cnt++;
                total += cnt;
                if (total >= cars) return true;
            }
            return total >= cars;
        };

        while (lo < hi) {
            long long mid = lo + (hi - lo) / 2;
            if (feasible(mid)) hi = mid;
            else lo = mid + 1;
        }
        return lo;
    }
};
