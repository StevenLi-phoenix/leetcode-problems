// @leetcode id=2846 questionId=3079 slug=minimum-edge-weight-equilibrium-queries-in-a-tree lang=cpp site=leetcode.com title="Minimum Edge Weight Equilibrium Queries in a Tree"
class Solution {
public:
    vector<int> minOperationsQueries(int n, vector<vector<int>>& edges, vector<vector<int>>& queries) {
        vector<vector<pair<int,int>>> adj(n);
        for (auto& e : edges) {
            adj[e[0]].push_back({e[1], e[2]});
            adj[e[1]].push_back({e[0], e[2]});
        }

        int LOG = 1;
        while ((1 << LOG) < n) LOG++;
        LOG++;

        vector<vector<int>> up(LOG, vector<int>(n, -1));
        vector<int> depth(n, 0);
        vector<array<int, 27>> cnt(n);
        cnt[0].fill(0);

        vector<int> order;
        order.reserve(n);
        vector<bool> visited(n, false);
        vector<int> stack = {0};
        visited[0] = true;
        while (!stack.empty()) {
            int u = stack.back();
            stack.pop_back();
            order.push_back(u);
            for (auto& [v, w] : adj[u]) {
                if (!visited[v]) {
                    visited[v] = true;
                    up[0][v] = u;
                    depth[v] = depth[u] + 1;
                    cnt[v] = cnt[u];
                    cnt[v][w]++;
                    stack.push_back(v);
                }
            }
        }

        for (int j = 1; j < LOG; j++) {
            for (int i = 0; i < n; i++) {
                int p = up[j - 1][i];
                up[j][i] = (p == -1) ? -1 : up[j - 1][p];
            }
        }

        auto lca = [&](int a, int b) -> int {
            if (depth[a] < depth[b]) swap(a, b);
            int diff = depth[a] - depth[b];
            for (int j = 0; j < LOG; j++) {
                if (diff & (1 << j)) a = up[j][a];
            }
            if (a == b) return a;
            for (int j = LOG - 1; j >= 0; j--) {
                if (up[j][a] != up[j][b]) {
                    a = up[j][a];
                    b = up[j][b];
                }
            }
            return up[0][a];
        };

        vector<int> answer(queries.size());
        for (size_t qi = 0; qi < queries.size(); qi++) {
            int a = queries[qi][0], b = queries[qi][1];
            int l = lca(a, b);
            int pathLen = depth[a] + depth[b] - 2 * depth[l];
            int best = 0;
            for (int w = 1; w <= 26; w++) {
                int c = cnt[a][w] + cnt[b][w] - 2 * cnt[l][w];
                best = max(best, c);
            }
            answer[qi] = pathLen - best;
        }

        return answer;
    }
};
