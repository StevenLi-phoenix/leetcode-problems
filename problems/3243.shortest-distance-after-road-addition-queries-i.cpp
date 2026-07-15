// @leetcode id=3243 questionId=3517 slug=shortest-distance-after-road-addition-queries-i lang=cpp site=leetcode.com title="Shortest Distance After Road Addition Queries I"
class Solution {
public:
    vector<int> shortestDistanceAfterQueries(int n, vector<vector<int>>& queries) {
        vector<vector<int>> adj(n);
        for (int i = 0; i + 1 < n; i++) adj[i].push_back(i + 1);

        vector<int> ans;
        for (auto& q : queries) {
            adj[q[0]].push_back(q[1]);

            vector<int> dist(n, -1);
            dist[0] = 0;
            queue<int> bfs;
            bfs.push(0);
            while (!bfs.empty()) {
                int u = bfs.front(); bfs.pop();
                for (int v : adj[u]) {
                    if (dist[v] == -1) {
                        dist[v] = dist[u] + 1;
                        bfs.push(v);
                    }
                }
            }
            ans.push_back(dist[n - 1]);
        }
        return ans;
    }
};
