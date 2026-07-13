// @leetcode id=1617 questionId=1740 slug=count-subtrees-with-max-distance-between-cities lang=cpp site=leetcode.com title="Count Subtrees With Max Distance Between Cities"
class Solution {
public:
    vector<int> countSubgraphsForEachDiameter(int n, vector<vector<int>>& edges) {
        vector<vector<int>> adj(n); // 0-indexed
        for (auto& e : edges) {
            int u = e[0] - 1, v = e[1] - 1;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        vector<int> ans(n - 1, 0);

        auto farthest = [&](int mask, int start) {
            vector<int> dist(n, -1);
            dist[start] = 0;
            queue<int> q;
            q.push(start);
            int bestNode = start, bestDist = 0;
            while (!q.empty()) {
                int u = q.front(); q.pop();
                for (int v : adj[u]) {
                    if (!(mask & (1 << v)) || dist[v] != -1) continue;
                    dist[v] = dist[u] + 1;
                    if (dist[v] > bestDist) { bestDist = dist[v]; bestNode = v; }
                    q.push(v);
                }
            }
            return make_pair(bestNode, bestDist);
        };

        for (int mask = 1; mask < (1 << n); mask++) {
            int size = __builtin_popcount(mask);
            if (size < 2) continue;

            int edgeCount = 0;
            for (auto& e : edges) {
                int u = e[0] - 1, v = e[1] - 1;
                if ((mask & (1 << u)) && (mask & (1 << v))) edgeCount++;
            }
            if (edgeCount != size - 1) continue; // not a connected induced subtree

            int start = __builtin_ctz(mask);
            auto [u, _] = farthest(mask, start);
            auto [v, diameter] = farthest(mask, u);
            ans[diameter - 1]++;
        }
        return ans;
    }
};
