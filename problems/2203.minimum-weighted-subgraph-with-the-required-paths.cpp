// @leetcode id=2203 questionId=2321 slug=minimum-weighted-subgraph-with-the-required-paths lang=cpp site=leetcode.com title="Minimum Weighted Subgraph With the Required Paths"
class Solution {
public:
    vector<long long> dijkstra(int n, vector<vector<pair<int,int>>>& adj, int src) {
        vector<long long> dist(n, LLONG_MAX / 2);
        dist[src] = 0;
        priority_queue<pair<long long,int>, vector<pair<long long,int>>, greater<>> pq;
        pq.push({0, src});

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

        return dist;
    }

    long long minimumWeight(int n, vector<vector<int>>& edges, int src1, int src2, int dest) {
        vector<vector<pair<int,int>>> adj(n), radj(n);
        for (auto& e : edges) {
            adj[e[0]].push_back({e[1], e[2]});
            radj[e[1]].push_back({e[0], e[2]});
        }

        vector<long long> d1 = dijkstra(n, adj, src1);
        vector<long long> d2 = dijkstra(n, adj, src2);
        vector<long long> d3 = dijkstra(n, radj, dest);

        const long long INF = LLONG_MAX / 2;
        long long best = INF;
        for (int m = 0; m < n; m++) {
            if (d1[m] >= INF || d2[m] >= INF || d3[m] >= INF) continue;
            long long total = d1[m] + d2[m] + d3[m];
            best = min(best, total);
        }

        return best >= INF ? -1 : best;
    }
};
