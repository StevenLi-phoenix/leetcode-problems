// @leetcode id=3585 questionId=3900 slug=find-weighted-median-node-in-tree lang=cpp site=leetcode.com title="Find Weighted Median Node in Tree"
class Solution {
public:
    static const int LOG = 18;
    vector<array<int, LOG>> up;
    vector<int> depth;
    vector<long long> dist;

    int lca(int u, int v) {
        if (depth[u] < depth[v]) swap(u, v);
        int diff = depth[u] - depth[v];
        for (int i = 0; i < LOG; i++) if ((diff >> i) & 1) u = up[u][i];
        if (u == v) return u;
        for (int i = LOG - 1; i >= 0; i--) {
            if (up[u][i] != up[v][i]) { u = up[u][i]; v = up[v][i]; }
        }
        return up[u][0];
    }

    vector<int> findMedian(int n, vector<vector<int>>& edges, vector<vector<int>>& queries) {
        vector<vector<pair<int, long long>>> adj(n);
        for (auto& e : edges) {
            adj[e[0]].push_back({e[1], e[2]});
            adj[e[1]].push_back({e[0], e[2]});
        }

        up.assign(n, {});
        depth.assign(n, 0);
        dist.assign(n, 0);

        // Iterative BFS from root 0 to avoid deep recursion.
        vector<int> order;
        order.reserve(n);
        vector<bool> visited(n, false);
        queue<int> q;
        q.push(0);
        visited[0] = true;
        up[0].fill(0);
        while (!q.empty()) {
            int u = q.front(); q.pop();
            order.push_back(u);
            for (auto& [v, w] : adj[u]) {
                if (visited[v]) continue;
                visited[v] = true;
                depth[v] = depth[u] + 1;
                dist[v] = dist[u] + w;
                up[v][0] = u;
                q.push(v);
            }
        }
        for (int i = 1; i < LOG; i++) {
            for (int v = 0; v < n; v++) up[v][i] = up[up[v][i - 1]][i - 1];
        }

        vector<int> ans;
        ans.reserve(queries.size());
        for (auto& qu : queries) {
            int u = qu[0], v = qu[1];
            int a = lca(u, v);
            long long T = dist[u] + dist[v] - 2 * dist[a];
            long long distU_LCA = dist[u] - dist[a];

            if (T == 0) {
                ans.push_back(u);
            } else if (2 * distU_LCA >= T) {
                // Median lies on the u..lca segment.
                int maxSteps = depth[u] - depth[a];
                int cur = u, stepsAccum = 0;
                for (int i = LOG - 1; i >= 0; i--) {
                    if (stepsAccum + (1 << i) > maxSteps) continue;
                    int cand = up[cur][i];
                    long long cum = 2 * (dist[u] - dist[cand]);
                    if (cum < T) { cur = cand; stepsAccum += (1 << i); }
                }
                ans.push_back(up[cur][0]);
            } else {
                // Median lies on the lca..v segment: find the deepest
                // ancestor of v (closest to v) still satisfying the
                // threshold when moving up toward lca.
                int maxSteps = depth[v] - depth[a];
                int cur = v, stepsAccum = 0;
                for (int i = LOG - 1; i >= 0; i--) {
                    if (stepsAccum + (1 << i) > maxSteps) continue;
                    int cand = up[cur][i];
                    long long cum = 2 * (dist[u] + dist[cand] - 2 * dist[a]);
                    if (cum >= T) { cur = cand; stepsAccum += (1 << i); }
                }
                ans.push_back(cur);
            }
        }
        return ans;
    }
};
