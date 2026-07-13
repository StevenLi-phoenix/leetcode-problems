// @leetcode id=2920 questionId=3179 slug=maximum-points-after-collecting-coins-from-all-nodes lang=cpp site=leetcode.com title="Maximum Points After Collecting Coins From All Nodes"
class Solution {
public:
    int maximumPoints(vector<vector<int>>& edges, vector<int>& coins, int k) {
        int n = coins.size();
        const int MAXH = 14; // 10^4 < 2^14, so beyond this halving does nothing
        vector<vector<int>> adj(n);
        for (auto& e : edges) {
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }

        // Iterative BFS to get parent-before-child order (avoids recursion
        // depth issues on a chain-shaped tree with n up to 1e5).
        vector<int> parent(n, -1), order;
        order.reserve(n);
        vector<bool> visited(n, false);
        vector<int> q = {0};
        visited[0] = true;
        for (int qi = 0; qi < (int)q.size(); qi++) {
            int u = q[qi];
            order.push_back(u);
            for (int v : adj[u])
                if (!visited[v]) { visited[v] = true; parent[v] = u; q.push_back(v); }
        }

        vector<array<int, 14>> dp(n);
        for (int i = order.size() - 1; i >= 0; i--) {
            int u = order[i];
            for (int h = 0; h < MAXH; h++) {
                int val = coins[u] >> h;
                long long takeAll = val - k;
                long long takeHalf = val / 2;
                for (int v : adj[u]) {
                    if (v == parent[u]) continue;
                    takeAll += dp[v][h];
                    takeHalf += dp[v][min(h + 1, MAXH - 1)];
                }
                dp[u][h] = (int)max(takeAll, takeHalf);
            }
        }
        return dp[0][0];
    }
};
