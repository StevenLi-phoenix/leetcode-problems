// @leetcode id=2187 questionId=2294 slug=minimum-time-to-complete-trips lang=cpp site=leetcode.com title="Minimum Time to Complete Trips"
class Solution {
public:
    long long minimumTime(vector<int>& time, int totalTrips) {
        long long lo = 1, hi = (long long)(*min_element(time.begin(), time.end())) * totalTrips;
        while (lo < hi) {
            long long mid = lo + (hi - lo) / 2;
            long long trips = 0;
            for (int t : time) {
                trips += mid / t;
                if (trips >= totalTrips) break;
            }
            if (trips >= totalTrips) hi = mid;
            else lo = mid + 1;
        }
        return lo;
    }
};
