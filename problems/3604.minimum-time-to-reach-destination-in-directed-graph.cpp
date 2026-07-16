// @leetcode id=3604 questionId=3916 slug=minimum-time-to-reach-destination-in-directed-graph lang=cpp site=leetcode.com title="Minimum Time to Reach Destination in Directed Graph"
class Solution {
public:
    int minTime(int n, vector<vector<int>>& edges) {
        vector<vector<array<int, 3>>> adj(n); // v, start, end
        for (auto& e : edges) {
            adj[e[0]].push_back({e[1], e[2], e[3]});
        }

        vector<long long> dist(n, LLONG_MAX);
        dist[0] = 0;
        priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<>> pq;
        pq.push({0, 0});

        while (!pq.empty()) {
            auto [d, u] = pq.top(); pq.pop();
            if (d > dist[u]) continue;
            for (auto& [v, start, end] : adj[u]) {
                if (d > end) continue;
                long long depart = max(d, (long long)start);
                long long arrive = depart + 1;
                if (arrive < dist[v]) {
                    dist[v] = arrive;
                    pq.push({arrive, v});
                }
            }
        }

        return dist[n - 1] == LLONG_MAX ? -1 : (int)dist[n - 1];
    }
};
