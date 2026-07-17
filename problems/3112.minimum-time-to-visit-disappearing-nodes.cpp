// @leetcode id=3112 questionId=3389 slug=minimum-time-to-visit-disappearing-nodes lang=cpp site=leetcode.com title="Minimum Time to Visit Disappearing Nodes"
class Solution {
public:
    vector<int> minimumTime(int n, vector<vector<int>>& edges, vector<int>& disappear) {
        vector<vector<pair<int,int>>> adj(n);
        for (auto& e : edges) {
            adj[e[0]].push_back({e[1], e[2]});
            adj[e[1]].push_back({e[0], e[2]});
        }

        vector<long long> dist(n, LLONG_MAX);
        dist[0] = 0;
        priority_queue<pair<long long,int>, vector<pair<long long,int>>, greater<>> pq;
        pq.push({0, 0});

        while (!pq.empty()) {
            auto [d, u] = pq.top(); pq.pop();
            if (d > dist[u]) continue;
            for (auto& [v, w] : adj[u]) {
                long long nd = d + w;
                if (nd < disappear[v] && nd < dist[v]) {
                    dist[v] = nd;
                    pq.push({nd, v});
                }
            }
        }

        vector<int> result(n);
        for (int i = 0; i < n; i++) {
            result[i] = (dist[i] == LLONG_MAX || dist[i] >= disappear[i]) ? -1 : (int)dist[i];
        }
        return result;
    }
};
