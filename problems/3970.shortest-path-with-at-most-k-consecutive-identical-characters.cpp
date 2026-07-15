// @leetcode id=3970 questionId=4104 slug=shortest-path-with-at-most-k-consecutive-identical-characters lang=cpp site=leetcode.com title="Shortest Path With At Most K Consecutive Identical Characters"
class Solution {
public:
    int shortestPath(int n, vector<vector<int>>& edges, string labels, int k) {
        vector<vector<pair<int, int>>> adj(n);
        for (auto& e : edges) {
            adj[e[0]].push_back({e[1], e[2]});
        }

        vector<vector<long long>> dist(n, vector<long long>(k + 1, LLONG_MAX));
        dist[0][1] = 0;

        priority_queue<tuple<long long, int, int>, vector<tuple<long long, int, int>>, greater<>> pq;
        pq.push({0, 0, 1});

        while (!pq.empty()) {
            auto [d, u, s] = pq.top(); pq.pop();
            if (d > dist[u][s]) continue;

            for (auto& [v, w] : adj[u]) {
                bool sameLabel = (labels[v] == labels[u]);
                int newStreak = sameLabel ? s + 1 : 1;
                if (newStreak > k) continue;
                long long nd = d + w;
                if (nd < dist[v][newStreak]) {
                    dist[v][newStreak] = nd;
                    pq.push({nd, v, newStreak});
                }
            }
        }

        long long best = LLONG_MAX;
        for (int s = 1; s <= k; s++) best = min(best, dist[n - 1][s]);
        return best == LLONG_MAX ? -1 : (int)best;
    }
};
