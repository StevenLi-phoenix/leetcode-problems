// @leetcode id=1377 questionId=1493 slug=frog-position-after-t-seconds lang=cpp site=leetcode.com title="Frog Position After T Seconds"
class Solution {
public:
    double frogPosition(int n, vector<vector<int>>& edges, int t, int target) {
        vector<vector<int>> adj(n + 1);
        for (auto& e : edges) {
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }

        vector<char> visited(n + 1, 0);
        vector<double> prob(n + 1, 0.0);
        vector<int> depth(n + 1, -1);
        prob[1] = 1.0;
        depth[1] = 0;
        visited[1] = 1;

        queue<int> q;
        q.push(1);
        while (!q.empty()) {
            int u = q.front();
            q.pop();
            if (depth[u] >= t) continue;

            vector<int> unvisitedNeighbors;
            for (int v : adj[u]) if (!visited[v]) unvisitedNeighbors.push_back(v);

            int cnt = unvisitedNeighbors.size();
            for (int v : unvisitedNeighbors) {
                visited[v] = 1;
                depth[v] = depth[u] + 1;
                prob[v] = prob[u] / cnt;
                q.push(v);
            }
        }

        if (depth[target] == -1) return 0.0;
        if (depth[target] == t) return prob[target];

        // Frog reached target before time t; it only stays put if target
        // has no children in the BFS tree (a dead end), otherwise it must
        // keep jumping away and can never be found there at time t.
        int childCount = 0;
        for (int v : adj[target]) {
            if (depth[v] == depth[target] + 1) childCount++;
        }
        return (childCount == 0) ? prob[target] : 0.0;
    }
};
