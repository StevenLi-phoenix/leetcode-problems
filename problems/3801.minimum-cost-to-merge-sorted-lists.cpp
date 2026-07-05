// @leetcode id=3801 questionId=4144 slug=minimum-cost-to-merge-sorted-lists lang=cpp site=leetcode.com title="Minimum Cost to Merge Sorted Lists"
class Solution {
public:
    long long minMergeCost(vector<vector<int>>& lists) {
        int n = lists.size();
        int full = 1 << n;

        vector<long long> sizeOf(full, 0);
        for (int mask = 1; mask < full; ++mask) {
            int lb = mask & (-mask);
            int i = __builtin_ctz(lb);
            sizeOf[mask] = sizeOf[mask ^ lb] + (long long)lists[i].size();
        }

        auto countLE = [&](long long v, int mask) {
            long long c = 0;
            for (int i = 0; i < n; ++i) {
                if (mask & (1 << i)) {
                    c += upper_bound(lists[i].begin(), lists[i].end(), (int)v) - lists[i].begin();
                }
            }
            return c;
        };

        vector<long long> medianOf(full, 0);
        for (int mask = 1; mask < full; ++mask) {
            long long target = (sizeOf[mask] - 1) / 2 + 1; // want the target-th smallest (1-indexed)
            long long lo = -1000000000, hi = 1000000000;
            while (lo < hi) {
                long long mid = lo + (hi - lo) / 2;
                if (countLE(mid, mask) >= target) hi = mid;
                else lo = mid + 1;
            }
            medianOf[mask] = lo;
        }

        vector<long long> dp(full, 0);
        for (int mask = 1; mask < full; ++mask) {
            if (__builtin_popcount(mask) < 2) continue;
            long long best = LLONG_MAX;
            for (int sub = (mask - 1) & mask; sub > 0; sub = (sub - 1) & mask) {
                int other = mask ^ sub;
                if (other == 0) continue;
                long long cost = dp[sub] + dp[other] + sizeOf[sub] + sizeOf[other] +
                                  llabs(medianOf[sub] - medianOf[other]);
                best = min(best, cost);
            }
            dp[mask] = best;
        }

        return dp[full - 1];
    }
};
