// @leetcode id=3650 questionId=3887 slug=minimum-cost-path-with-edge-reversals lang=cpp site=leetcode.com title="Minimum Cost Path with Edge Reversals"
class Solution {
public:
int minCost(int n, vector<vector<int>>& edges) {
vector<vector<pair<int,int>>> adj(n);
for (auto& e : edges) {
int u = e[0], v = e[1], w = e[2];
adj[u].push_back({v, w});
adj[v].push_back({u, 2*w});
}
vector<long long> dist(n, LLONG_MAX);
priority_queue<pair<long long,int>, vector<pair<long long,int>>, greater<>> pq;
dist[0] = 0;
pq.push({0, 0});
while (!pq.empty()) {
auto [d, u] = pq.top(); pq.pop();
if (d > dist[u]) continue;
for (auto [v, w] : adj[u]) {
if (dist[u] + w < dist[v]) {
dist[v] = dist[u] + w;
pq.push({dist[v], v});
}
}
}
return dist[n-1] == LLONG_MAX ? -1 : (int)dist[n-1];
}
};
