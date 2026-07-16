// @leetcode id=1466 questionId=1576 slug=reorder-routes-to-make-all-paths-lead-to-the-city-zero lang=cpp site=leetcode.com title="Reorder Routes to Make All Paths Lead to the City Zero"
class Solution {
public:
    int minReorder(int n, vector<vector<int>>& connections) {
        vector<vector<pair<int, int>>> adj(n); // neighbor, needsReversal(1 if edge originally points away from this node)
        for (auto& c : connections) {
            adj[c[0]].push_back({c[1], 1});
            adj[c[1]].push_back({c[0], 0});
        }

        vector<bool> visited(n, false);
        queue<int> bfs;
        bfs.push(0);
        visited[0] = true;
        int count = 0;

        while (!bfs.empty()) {
            int u = bfs.front(); bfs.pop();
            for (auto& [v, needsReversal] : adj[u]) {
                if (!visited[v]) {
                    visited[v] = true;
                    count += needsReversal;
                    bfs.push(v);
                }
            }
        }
        return count;
    }
};
