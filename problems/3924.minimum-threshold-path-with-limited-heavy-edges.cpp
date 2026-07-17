// @leetcode id=3924 questionId=4102 slug=minimum-threshold-path-with-limited-heavy-edges lang=cpp site=leetcode.com title="Minimum Threshold Path With Limited Heavy Edges"
class Solution {
public:
    bool check(int n, vector<vector<int>>& edges, int source, int target, int k, long long threshold) {
        vector<vector<pair<int,int>>> adj(n); // (neighbor, weight)
        for (auto& e : edges) {
            adj[e[0]].push_back({e[1], e[2]});
            adj[e[1]].push_back({e[0], e[2]});
        }

        vector<int> dist(n, INT_MAX);
        dist[source] = 0;
        deque<int> dq;
        dq.push_back(source);

        while (!dq.empty()) {
            int u = dq.front();
            dq.pop_front();
            for (auto& [v, w] : adj[u]) {
                int cost = (w > threshold) ? 1 : 0;
                if (dist[u] + cost < dist[v]) {
                    dist[v] = dist[u] + cost;
                    if (cost == 0) dq.push_front(v);
                    else dq.push_back(v);
                }
            }
        }

        return dist[target] != INT_MAX && dist[target] <= k;
    }

    int minimumThreshold(int n, vector<vector<int>>& edges, int source, int target, int k) {
        if (source == target) return 0;
        if (edges.empty()) return -1;

        long long maxWeight = 0;
        for (auto& e : edges) maxWeight = max(maxWeight, (long long)e[2]);

        if (!check(n, edges, source, target, k, maxWeight)) return -1;

        long long lo = 0, hi = maxWeight;
        while (lo < hi) {
            long long mid = lo + (hi - lo) / 2;
            if (check(n, edges, source, target, k, mid)) {
                hi = mid;
            } else {
                lo = mid + 1;
            }
        }

        return (int)lo;
    }
};
