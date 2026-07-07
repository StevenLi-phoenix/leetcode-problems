// @leetcode id=3367 questionId=3675 slug=maximize-sum-of-weights-after-edge-removals lang=cpp site=leetcode.com title="Maximize Sum of Weights after Edge Removals"
class Solution {
public:
    long long maximizeSumOfWeights(vector<vector<int>>& edges, int k) {
        int n = edges.size() + 1;
        vector<vector<pair<int, int>>> adj(n); // (neighbor, weight)
        for (auto& e : edges) {
            adj[e[0]].push_back({e[1], e[2]});
            adj[e[1]].push_back({e[0], e[2]});
        }

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
            for (auto& [v, w] : adj[u]) {
                if (!visited[v]) {
                    visited[v] = true;
                    parent[v] = u;
                    q.push(v);
                }
            }
        }

        vector<long long> dpKeep(n, 0), dpNoKeep(n, 0);

        for (int idx = n - 1; idx >= 0; --idx) {
            int u = order[idx];
            long long base = 0;
            vector<long long> gains;

            for (auto& [v, w] : adj[u]) {
                if (v == parent[u]) continue;
                base += dpNoKeep[v];
                long long gain = (dpKeep[v] + w) - dpNoKeep[v];
                if (gain > 0) gains.push_back(gain);
            }

            sort(gains.begin(), gains.end(), greater<long long>());
            vector<long long> prefix(gains.size() + 1, 0);
            for (int i = 0; i < (int)gains.size(); ++i) prefix[i + 1] = prefix[i] + gains[i];

            int takeNoKeep = min((int)gains.size(), k);
            int takeKeep = min((int)gains.size(), max(0, k - 1));

            dpNoKeep[u] = base + prefix[takeNoKeep];
            dpKeep[u] = base + prefix[takeKeep];
        }

        return dpNoKeep[0];
    }
};
