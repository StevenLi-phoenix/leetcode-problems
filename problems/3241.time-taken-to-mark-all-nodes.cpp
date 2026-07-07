// @leetcode id=3241 questionId=3532 slug=time-taken-to-mark-all-nodes lang=cpp site=leetcode.com title="Time Taken to Mark All Nodes"
class Solution {
public:
    vector<int> timeTaken(vector<vector<int>>& edges) {
        int n = edges.size() + 1;
        vector<vector<int>> adj(n);
        for (auto& e : edges) {
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }

        auto weightTo = [](int target) -> long long {
            return (target % 2 == 1) ? 1 : 2;
        };

        vector<int> parent(n, -1), order;
        order.reserve(n);
        vector<bool> visited(n, false);
        queue<int> q;
        q.push(0);
        visited[0] = true;
        while (!q.empty()) {
            int u = q.front();
            q.pop();
            order.push_back(u);
            for (int v : adj[u]) {
                if (!visited[v]) {
                    visited[v] = true;
                    parent[v] = u;
                    q.push(v);
                }
            }
        }

        vector<long long> down1(n, 0), secondBest(n, 0), up(n, -1);
        vector<int> bestChild(n, -1);

        for (int idx = n - 1; idx >= 0; --idx) {
            int u = order[idx];
            for (int v : adj[u]) {
                if (v == parent[u]) continue;
                long long candidate = down1[v] + weightTo(v);
                if (candidate > down1[u]) {
                    secondBest[u] = down1[u];
                    down1[u] = candidate;
                    bestChild[u] = v;
                } else if (candidate > secondBest[u]) {
                    secondBest[u] = candidate;
                }
            }
        }

        for (int u : order) {
            for (int v : adj[u]) {
                if (v == parent[u]) continue;
                long long excludeBest = (bestChild[u] == v) ? secondBest[u] : down1[u];
                long long bestExcl = max((long long)0, excludeBest);
                if (up[u] != -1) bestExcl = max(bestExcl, up[u]);
                up[v] = weightTo(u) + bestExcl;
            }
        }

        vector<int> ans(n);
        for (int u = 0; u < n; ++u) {
            long long t = down1[u];
            if (up[u] != -1) t = max(t, up[u]);
            ans[u] = (int)t;
        }
        return ans;
    }
};
