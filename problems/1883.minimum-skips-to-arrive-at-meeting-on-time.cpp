// @leetcode id=1883 questionId=2013 slug=minimum-skips-to-arrive-at-meeting-on-time lang=cpp site=leetcode.com title="Minimum Skips to Arrive at Meeting On Time"
class Solution {
public:
    int minSkips(vector<int>& dist, int speed, int hoursBefore) {
        int n = dist.size();
        // dp[i][j] = min time (multiplied by speed) after traveling i roads with j skips
        // After i-th road (0-indexed), if not last road, need to wait for next integer hour
        const long long INF = 1e18;
        vector<vector<long long>> dp(n + 1, vector<long long>(n + 1, INF));
        dp[0][0] = 0;
        
        for (int i = 0; i < n; i++) {
            for (int j = 0; j <= i; j++) {
                if (dp[i][j] == INF) continue;
                long long cur = dp[i][j] + dist[i];
                
                // Option 1: Skip rest after road i (no ceiling needed)
                if (j + 1 <= n && dp[i][j+1] != -1) {
                    dp[i+1][j+1] = min(dp[i+1][j+1], cur);
                }
                
                // Option 2: No skip (if not last road, round up to next multiple of speed)
                long long rounded;
                if (i == n - 1) {
                    rounded = cur; // last road, no rounding needed
                } else {
                    rounded = (cur + speed - 1) / speed * speed;
                }
                dp[i+1][j] = min(dp[i+1][j], rounded);
            }
        }
        
        // Find minimum skips where total time <= hoursBefore * speed
        for (int j = 0; j <= n; j++) {
            if (dp[n][j] <= (long long)hoursBefore * speed) return j;
        }
        return -1;
    }
};
