// @leetcode id=1928 questionId=2040 slug=minimum-cost-to-reach-destination-in-time lang=cpp site=leetcode.com title="Minimum Cost to Reach Destination in Time"
class Solution {
public:
    int minCost(int maxTime, vector<vector<int>>& edges, vector<int>& passingFees) {
        int n = passingFees.size();
        const int INF = INT_MAX / 2;
        vector<vector<pair<int,int>>> adj(n); // (neighbor, weight)
        for (auto& e : edges) {
            adj[e[0]].push_back({e[1], e[2]});
            adj[e[1]].push_back({e[0], e[2]});
        }

        // dp[t][city] = min cost to reach city using exactly t minutes total.
        vector<vector<int>> dp(maxTime + 1, vector<int>(n, INF));
        dp[0][0] = passingFees[0];

        for (int t = 0; t < maxTime; t++) {
            for (int city = 0; city < n; city++) {
                if (dp[t][city] == INF) continue;
                for (auto& [v, w] : adj[city]) {
                    if (t + w > maxTime) continue;
                    dp[t + w][v] = min(dp[t + w][v], dp[t][city] + passingFees[v]);
                }
            }
        }

        int best = INF;
        for (int t = 0; t <= maxTime; t++) best = min(best, dp[t][n - 1]);
        return best == INF ? -1 : best;
    }
};
