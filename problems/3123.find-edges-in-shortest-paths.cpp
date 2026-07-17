// @leetcode id=3123 questionId=3386 slug=find-edges-in-shortest-paths lang=cpp site=leetcode.com title="Find Edges in Shortest Paths"
class Solution {
public:
    vector<long long> dijkstra(int n, int src, vector<vector<pair<int,int>>>& adj) {
        vector<long long> dist(n, LLONG_MAX);
        dist[src] = 0;
        priority_queue<pair<long long,int>, vector<pair<long long,int>>, greater<>> pq;
        pq.push({0, src});
        while (!pq.empty()) {
            auto [d, u] = pq.top();
            pq.pop();
            if (d > dist[u]) continue;
            for (auto& [v, w] : adj[u]) {
                long long nd = d + w;
                if (nd < dist[v]) {
                    dist[v] = nd;
                    pq.push({nd, v});
                }
            }
        }
        return dist;
    }

    vector<bool> findAnswer(int n, vector<vector<int>>& edges) {
        vector<vector<pair<int,int>>> adj(n);
        for (auto& e : edges) {
            adj[e[0]].push_back({e[1], e[2]});
            adj[e[1]].push_back({e[0], e[2]});
        }

        vector<long long> distFrom0 = dijkstra(n, 0, adj);
        vector<long long> distFromN = dijkstra(n, n - 1, adj);

        long long total = distFrom0[n - 1];
        vector<bool> answer(edges.size(), false);

        if (total == LLONG_MAX) return answer;

        for (size_t i = 0; i < edges.size(); i++) {
            int u = edges[i][0], v = edges[i][1], w = edges[i][2];
            if (distFrom0[u] == LLONG_MAX || distFromN[v] == LLONG_MAX) continue;
            if (distFrom0[u] + w + distFromN[v] == total) { answer[i] = true; continue; }
            if (distFrom0[v] == LLONG_MAX || distFromN[u] == LLONG_MAX) continue;
            if (distFrom0[v] + w + distFromN[u] == total) answer[i] = true;
        }

        return answer;
    }
};
