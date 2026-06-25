// @leetcode id=2742 questionId=2808 slug=painting-the-walls lang=cpp site=leetcode.com title="Painting the Walls"
class Solution {
public:
    int paintWalls(vector<int>& cost, vector<int>& time) {
        int n = cost.size();
        const long long INF = 1e18;

        vector<vector<long long>> dp(n + 1, vector<long long>(n + 1, INF));
        dp[0][0] = 0;

        for (int i = 0; i < n; i++) {
            for (int k = min(i + 1, n); k >= 1; k--) {
                for (int t = n; t >= 0; t--) {
                    if (dp[k - 1][t] < INF) {
                        int new_t = min(n, t + time[i]);
                        dp[k][new_t] = min(dp[k][new_t], dp[k - 1][t] + cost[i]);
                    }
                }
            }
        }

        long long result = INF;
        for (int k = 0; k <= n; k++) {
            int required = max(0, n - k);
            for (int t = required; t <= n; t++) {
                result = min(result, dp[k][t]);
            }
        }
        return result;
    }
};
