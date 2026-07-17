// @leetcode id=3538 questionId=3833 slug=merge-operations-for-minimum-travel-time lang=cpp site=leetcode.com title="Merge Operations for Minimum Travel Time"
class Solution {
public:
    int minTravelTime(int l, int n, int k, vector<int>& position, vector<int>& time) {
        // segments 0..n-2 have rates time[0..n-2]; time[n-1] unused.
        // Choose boundaries 0=b0<b1<...<bm=n-1 (m = n-1-k segments).
        // segment j: rate = sum(time[b_{j-1}+1 .. b_j]), span = position[b_{j+1}] - position[b_j].
        vector<long long> prefixTime(n + 1, 0);
        for (int i = 0; i < n - 1; i++) prefixTime[i + 1] = prefixTime[i] + time[i];

        int m = (n - 1) - k; // number of final segments

        const long long INF = LLONG_MAX / 2;
        // dp[prevIdx][cur][g]: prevIdx in [0..n-1] represents prevReal = prevIdx-1 (prevIdx=0 => prevReal=-1)
        vector<vector<vector<long long>>> dp(n + 1, vector<vector<long long>>(n, vector<long long>(m + 1, INF)));
        dp[0][0][0] = 0; // prevReal=-1, cur=0, g=0

        for (int prevIdx = 0; prevIdx <= n - 1; prevIdx++) {
            for (int cur = 0; cur < n; cur++) {
                for (int g = 0; g < m; g++) {
                    if (dp[prevIdx][cur][g] >= INF) continue;
                    if (cur >= n - 1) continue;
                    long long rate = prefixTime[cur + 1] - prefixTime[prevIdx];
                    for (int nxt = cur + 1; nxt <= n - 1; nxt++) {
                        long long span = position[nxt] - position[cur];
                        long long cost = dp[prevIdx][cur][g] + rate * span;
                        if (cost < dp[cur + 1][nxt][g + 1]) {
                            dp[cur + 1][nxt][g + 1] = cost;
                        }
                    }
                }
            }
        }

        long long best = INF;
        for (int prevIdx = 0; prevIdx <= n - 1; prevIdx++) {
            best = min(best, dp[prevIdx][n - 1][m]);
        }

        return (int)best;
    }
};
