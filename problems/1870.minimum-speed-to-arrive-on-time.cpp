// @leetcode id=1870 questionId=2000 slug=minimum-speed-to-arrive-on-time lang=cpp site=leetcode.com title="Minimum Speed to Arrive on Time"
class Solution {
public:
    int minSpeedOnTime(vector<int>& dist, double hour) {
        int n = dist.size();
        long long H = llround(hour * 100.0);

        auto feasible = [&](long long speed) -> bool {
            long long timeInt = 0;
            for (int i = 0; i + 1 < n; i++) {
                timeInt += (dist[i] + speed - 1) / speed;
            }
            long long remaining = H - 100 * timeInt;
            if (remaining < 0) return false;
            return 100LL * dist[n - 1] <= remaining * speed;
        };

        long long lo = 1, hi = 10000000, ans = -1;
        while (lo <= hi) {
            long long mid = lo + (hi - lo) / 2;
            if (feasible(mid)) {
                ans = mid;
                hi = mid - 1;
            } else {
                lo = mid + 1;
            }
        }
        return (int)ans;
    }
};
