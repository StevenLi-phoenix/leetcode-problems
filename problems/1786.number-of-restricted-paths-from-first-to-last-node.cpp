// @leetcode id=1786 questionId=1912 slug=number-of-restricted-paths-from-first-to-last-node lang=cpp site=leetcode.com title="Number of Restricted Paths From First to Last Node"
class Solution {
public:
    int countRestrictedPaths(int n, vector<vector<int>>& edges) {
        const long long MOD = 1'000'000'007;
        vector<vector<pair<int,int>>> adj(n + 1); // (neighbor, weight)
        for (auto& e : edges) {
            adj[e[0]].push_back({e[1], e[2]});
            adj[e[1]].push_back({e[0], e[2]});
        }

        // Dijkstra from node n to get distanceToLastNode for every node.
        vector<long long> dist(n + 1, LLONG_MAX);
        dist[n] = 0;
        priority_queue<pair<long long,int>, vector<pair<long long,int>>, greater<>> pq;
        pq.push({0, n});
        while (!pq.empty()) {
            auto [d, u] = pq.top(); pq.pop();
            if (d > dist[u]) continue;
            for (auto& [v, w] : adj[u]) {
                if (dist[u] + w < dist[v]) {
                    dist[v] = dist[u] + w;
                    pq.push({dist[v], v});
                }
            }
        }

        // Process nodes in increasing distance order so that when computing
        // ways[u], every neighbor v with dist[v] < dist[u] is already final.
        vector<int> order(n);
        for (int i = 0; i < n; i++) order[i] = i + 1;
        sort(order.begin(), order.end(), [&](int a, int b) { return dist[a] < dist[b]; });

        vector<long long> ways(n + 1, 0);
        ways[n] = 1;
        for (int u : order) {
            if (u == n) continue;
            long long total = 0;
            for (auto& [v, w] : adj[u])
                if (dist[v] < dist[u]) total = (total + ways[v]) % MOD;
            ways[u] = total;
        }
        return (int)ways[1];
    }
};
