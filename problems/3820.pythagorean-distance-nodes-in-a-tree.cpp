// @leetcode id=3820 questionId=4180 slug=pythagorean-distance-nodes-in-a-tree lang=cpp site=leetcode.com title="Pythagorean Distance Nodes in a Tree"
class Solution {
public:
    vector<int> bfs(int src, int n, vector<vector<int>>& adj) {
        vector<int> dist(n, -1);
        queue<int> q;
        q.push(src);
        dist[src] = 0;
        while (!q.empty()) {
            int u = q.front(); q.pop();
            for (int v : adj[u]) {
                if (dist[v] == -1) {
                    dist[v] = dist[u] + 1;
                    q.push(v);
                }
            }
        }
        return dist;
    }
    
    int specialNodes(int n, vector<vector<int>>& edges, int x, int y, int z) {
        vector<vector<int>> adj(n);
        for (auto& e : edges) {
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }
        
        vector<int> dx = bfs(x, n, adj);
        vector<int> dy = bfs(y, n, adj);
        vector<int> dz = bfs(z, n, adj);
        
        int count = 0;
        for (int u = 0; u < n; u++) {
            long long a = dx[u], b = dy[u], c = dz[u];
            // Sort a, b, c
            if (a > b) swap(a, b);
            if (b > c) swap(b, c);
            if (a > b) swap(a, b);
            // Check a^2 + b^2 == c^2
            if (a * a + b * b == c * c) count++;
        }
        
        return count;
    }
};
