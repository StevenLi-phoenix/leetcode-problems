// @leetcode id=882 questionId=918 slug=reachable-nodes-in-subdivided-graph lang=cpp site=leetcode.com title="Reachable Nodes In Subdivided Graph"
class Solution {
public:
    int reachableNodes(vector<vector<int>>& edges, int maxMoves, int n) {
        vector<vector<pair<int,int>>> adj(n); // (neighbor, cnt)
        for (auto& e : edges) {
            adj[e[0]].push_back({e[1], e[2]});
            adj[e[1]].push_back({e[0], e[2]});
        }

        vector<long long> dist(n, LLONG_MAX);
        dist[0] = 0;
        priority_queue<pair<long long,int>, vector<pair<long long,int>>, greater<>> pq;
        pq.push({0, 0});

        while (!pq.empty()) {
            auto [d, u] = pq.top();
            pq.pop();
            if (d > dist[u]) continue;
            for (auto& [v, cnt] : adj[u]) {
                long long nd = d + cnt + 1;
                if (nd < dist[v]) {
                    dist[v] = nd;
                    pq.push({nd, v});
                }
            }
        }

        int answer = 0;
        for (int i = 0; i < n; i++) {
            if (dist[i] <= maxMoves) answer++;
        }

        for (auto& e : edges) {
            int u = e[0], v = e[1], cnt = e[2];
            long long usedFromU = (dist[u] <= maxMoves) ? min((long long)cnt, maxMoves - dist[u]) : 0;
            long long usedFromV = (dist[v] <= maxMoves) ? min((long long)cnt, maxMoves - dist[v]) : 0;
            answer += (int)min((long long)cnt, usedFromU + usedFromV);
        }

        return answer;
    }
};
