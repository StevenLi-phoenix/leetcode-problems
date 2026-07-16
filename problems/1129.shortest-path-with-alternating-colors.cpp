// @leetcode id=1129 questionId=1229 slug=shortest-path-with-alternating-colors lang=cpp site=leetcode.com title="Shortest Path with Alternating Colors"
class Solution {
public:
    vector<int> shortestAlternatingPaths(int n, vector<vector<int>>& redEdges, vector<vector<int>>& blueEdges) {
        vector<vector<int>> adj[2];
        adj[0].resize(n);
        adj[1].resize(n);
        for (auto& e : redEdges) adj[0][e[0]].push_back(e[1]);
        for (auto& e : blueEdges) adj[1][e[0]].push_back(e[1]);

        vector<vector<int>> dist(n, vector<int>(2, -1));
        queue<pair<int, int>> bfs;
        dist[0][0] = 0;
        dist[0][1] = 0;
        bfs.push({0, 0});
        bfs.push({0, 1});

        while (!bfs.empty()) {
            auto [node, color] = bfs.front(); bfs.pop();
            int nextColor = 1 - color;
            for (int nb : adj[nextColor][node]) {
                if (dist[nb][nextColor] == -1) {
                    dist[nb][nextColor] = dist[node][color] + 1;
                    bfs.push({nb, nextColor});
                }
            }
        }

        vector<int> ans(n);
        for (int i = 0; i < n; i++) {
            if (dist[i][0] == -1) ans[i] = dist[i][1];
            else if (dist[i][1] == -1) ans[i] = dist[i][0];
            else ans[i] = min(dist[i][0], dist[i][1]);
        }
        return ans;
    }
};
