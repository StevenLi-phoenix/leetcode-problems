// @leetcode id=3553 questionId=3853 slug=minimum-weighted-subgraph-with-the-required-paths-ii lang=cpp site=leetcode.com title="Minimum Weighted Subgraph With the Required Paths II"
class Solution {
public:
    vector<int> minimumWeight(vector<vector<int>>& edges, vector<vector<int>>& queries) {
        // In a tree, the minimum Steiner tree connecting 3 nodes {a,b,c}
        // equals (dist(a,b) + dist(b,c) + dist(a,c)) / 2 (each of the three
        // pairwise shared-path segments gets counted exactly twice).
        int n = edges.size() + 1;
        vector<vector<pair<int,int>>> adj(n); // (neighbor, weight)
        for (auto& e : edges) {
            adj[e[0]].push_back({e[1], e[2]});
            adj[e[1]].push_back({e[0], e[2]});
        }

        int LOG = 1;
        while ((1 << LOG) < n) LOG++;
        LOG = max(LOG, 1);
        vector<vector<int>> up(LOG, vector<int>(n, 0));
        vector<int> depth(n, 0);
        vector<long long> distRoot(n, 0);

        vector<int> parent(n, -1);
        vector<bool> visited(n, false);
        vector<int> order = {0};
        visited[0] = true;
        for (int qi = 0; qi < (int)order.size(); qi++) {
            int u = order[qi];
            for (auto& [v, w] : adj[u])
                if (!visited[v]) {
                    visited[v] = true;
                    parent[v] = u;
                    depth[v] = depth[u] + 1;
                    distRoot[v] = distRoot[u] + w;
                    order.push_back(v);
                }
        }

        for (int i = 0; i < n; i++) up[0][i] = (parent[i] == -1) ? i : parent[i];
        for (int k = 1; k < LOG; k++)
            for (int i = 0; i < n; i++) up[k][i] = up[k - 1][up[k - 1][i]];

        auto lca = [&](int u, int v) {
            if (depth[u] < depth[v]) swap(u, v);
            int diff = depth[u] - depth[v];
            for (int k = 0; k < LOG; k++)
                if (diff >> k & 1) u = up[k][u];
            if (u == v) return u;
            for (int k = LOG - 1; k >= 0; k--)
                if (up[k][u] != up[k][v]) { u = up[k][u]; v = up[k][v]; }
            return up[0][u];
        };

        auto dist = [&](int u, int v) {
            int l = lca(u, v);
            return distRoot[u] + distRoot[v] - 2 * distRoot[l];
        };

        vector<int> ans(queries.size());
        for (int i = 0; i < (int)queries.size(); i++) {
            int a = queries[i][0], b = queries[i][1], c = queries[i][2];
            long long total = dist(a, b) + dist(b, c) + dist(a, c);
            ans[i] = (int)(total / 2);
        }
        return ans;
    }
};
