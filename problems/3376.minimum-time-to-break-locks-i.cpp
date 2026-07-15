// @leetcode id=3376 questionId=3649 slug=minimum-time-to-break-locks-i lang=cpp site=leetcode.com title="Minimum Time to Break Locks I"
class Solution {
public:
    int findMinimumTime(vector<int>& strength, int k) {
        int n = strength.size();
        int full = 1 << n;
        vector<int> dp(full, INT_MAX);
        dp[0] = 0;
        for (int mask = 0; mask < full; mask++) {
            if (dp[mask] == INT_MAX) continue;
            int cnt = __builtin_popcount(mask);
            long long x = 1 + (long long)cnt * k;
            for (int j = 0; j < n; j++) {
                if (mask & (1 << j)) continue;
                long long time = (strength[j] + x - 1) / x;
                int nextMask = mask | (1 << j);
                int candidate = dp[mask] + (int)time;
                if (candidate < dp[nextMask]) dp[nextMask] = candidate;
            }
        }
        return dp[full - 1];
    }
};
