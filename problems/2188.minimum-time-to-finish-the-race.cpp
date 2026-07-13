// @leetcode id=2188 questionId=2295 slug=minimum-time-to-finish-the-race lang=cpp site=leetcode.com title="Minimum Time to Finish the Race"
class Solution {
public:
    int minimumFinishTime(vector<vector<int>>& tires, int changeTime, int numLaps) {
        // Since r >= 2, running any single tire for more than ~17 laps in a
        // row is never worth it (a fresh tire + changeTime beats the
        // exponential blow-up), so only streak lengths up to that cap
        // matter.
        const int CAP = 18;
        int maxStreak = min(numLaps, CAP);
        vector<long long> best(maxStreak + 1, LLONG_MAX);

        for (auto& tire : tires) {
            long long f = tire[0], r = tire[1];
            long long time = 0, lap = f;
            for (int k = 1; k <= maxStreak; k++) {
                time += lap;
                best[k] = min(best[k], time);
                lap *= r;
                if (lap > (long long)2e14) break; // guard against overflow on huge r
            }
        }

        vector<long long> dp(numLaps + 1, LLONG_MAX);
        dp[0] = 0;
        for (int i = 1; i <= numLaps; i++) {
            for (int k = 1; k <= min(i, maxStreak); k++) {
                if (best[k] == LLONG_MAX) continue;
                long long prev = dp[i - k];
                if (prev == LLONG_MAX) continue;
                long long cost = prev + best[k] + (i - k > 0 ? changeTime : 0);
                dp[i] = min(dp[i], cost);
            }
        }
        return (int)dp[numLaps];
    }
};
