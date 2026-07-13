// @leetcode id=3733 questionId=4048 slug=minimum-time-to-complete-all-deliveries lang=cpp site=leetcode.com title="Minimum Time to Complete All Deliveries"
class Solution {
public:
    long long minimumTime(vector<int>& d, vector<int>& r) {
        // Only one drone can deliver per hour, so an hour is fully wasted
        // only if BOTH drones are recharging (a multiple of lcm(r1,r2));
        // otherwise the non-recharging drone can use it. Feasibility for
        // T hours needs each drone's own capacity to cover its own count,
        // plus the shared capacity to cover the total.
        long long r1 = r[0], r2 = r[1];
        long long l = lcm(r1, r2);
        long long d1 = d[0], d2 = d[1];

        auto feasible = [&](long long T) {
            long long cap1 = T - T / r1;
            long long cap2 = T - T / r2;
            long long capShared = T - T / l;
            return cap1 >= d1 && cap2 >= d2 && capShared >= d1 + d2;
        };

        long long lo = 1, hi = 4e9;
        while (lo < hi) {
            long long mid = lo + (hi - lo) / 2;
            if (feasible(mid)) hi = mid;
            else lo = mid + 1;
        }
        return lo;
    }
};
