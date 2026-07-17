// @leetcode id=3203 questionId=3439 slug=find-minimum-diameter-after-merging-two-trees lang=cpp site=leetcode.com title="Find Minimum Diameter After Merging Two Trees"
class Solution {
public:
    pair<int,int> bfsFarthest(int start, vector<vector<int>>& adj) {
        int n = adj.size();
        vector<int> dist(n, -1);
        queue<int> q;
        dist[start] = 0;
        q.push(start);
        int farNode = start;

        while (!q.empty()) {
            int u = q.front(); q.pop();
            if (dist[u] > dist[farNode]) farNode = u;
            for (int v : adj[u]) {
                if (dist[v] == -1) {
                    dist[v] = dist[u] + 1;
                    q.push(v);
                }
            }
        }

        return {farNode, dist[farNode]};
    }

    int diameter(vector<vector<int>>& edges, int n) {
        vector<vector<int>> adj(n);
        for (auto& e : edges) {
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }
        if (n == 1) return 0;
        auto [node1, d1] = bfsFarthest(0, adj);
        auto [node2, d2] = bfsFarthest(node1, adj);
        return d2;
    }

    int minimumDiameterAfterMerge(vector<vector<int>>& edges1, vector<vector<int>>& edges2) {
        int n = edges1.size() + 1;
        int m = edges2.size() + 1;

        int d1 = diameter(edges1, n);
        int d2 = diameter(edges2, m);

        int combined = (d1 + 1) / 2 + (d2 + 1) / 2 + 1;

        return max({d1, d2, combined});
    }
};
