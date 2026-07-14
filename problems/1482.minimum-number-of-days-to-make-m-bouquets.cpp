// @leetcode id=1482 questionId=1605 slug=minimum-number-of-days-to-make-m-bouquets lang=cpp site=leetcode.com title="Minimum Number of Days to Make m Bouquets"
class Solution {
public:
    int minDays(vector<int>& bloomDay, int m, int k) {
        long long need = (long long)m * k;
        if (need > (long long)bloomDay.size()) return -1;

        auto feasible = [&](int day) -> bool {
            int adjacent = 0;
            long long bouquets = 0;
            for (int b : bloomDay) {
                if (b <= day) {
                    adjacent++;
                    if (adjacent == k) {
                        bouquets++;
                        adjacent = 0;
                    }
                } else {
                    adjacent = 0;
                }
            }
            return bouquets >= m;
        };

        int lo = 1, hi = *max_element(bloomDay.begin(), bloomDay.end());
        while (lo < hi) {
            int mid = lo + (hi - lo) / 2;
            if (feasible(mid)) hi = mid;
            else lo = mid + 1;
        }
        return lo;
    }
};
