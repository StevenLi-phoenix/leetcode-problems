// @leetcode id=2608 questionId=2671 slug=shortest-cycle-in-a-graph lang=cpp site=leetcode.com title="Shortest Cycle in a Graph"
class Solution {
public:
    int findShortestCycle(int n, vector<vector<int>>& edges) {
        vector<vector<int>> adj(n);
        for (auto& e : edges) {
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }

        int ans = INT_MAX;

        for (int start = 0; start < n; start++) {
            vector<int> dist(n, -1);
            queue<int> q;
            q.push(start);
            dist[start] = 0;

            while (!q.empty()) {
                int u = q.front();
                q.pop();

                for (int v : adj[u]) {
                    if (dist[v] == -1) {
                        dist[v] = dist[u] + 1;
                        q.push(v);
                    } else if (dist[v] >= dist[u]) {
                        ans = min(ans, dist[u] + dist[v] + 1);
                    }
                }
            }
        }

        return (ans == INT_MAX) ? -1 : ans;
    }
};
