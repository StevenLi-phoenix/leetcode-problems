// @leetcode id=2493 questionId=2583 slug=divide-nodes-into-the-maximum-number-of-groups lang=cpp site=leetcode.com title="Divide Nodes Into the Maximum Number of Groups"
class Solution {
public:
    int bfsMaxDepth(int start, vector<vector<int>>& adj, int n) {
        vector<int> dist(n + 1, -1);
        queue<int> q;
        dist[start] = 0;
        q.push(start);
        int maxDepth = 0;
        while (!q.empty()) {
            int u = q.front(); q.pop();
            maxDepth = max(maxDepth, dist[u]);
            for (int v : adj[u]) {
                if (dist[v] == -1) {
                    dist[v] = dist[u] + 1;
                    q.push(v);
                }
            }
        }
        return maxDepth;
    }

    int magnificentSets(int n, vector<vector<int>>& edges) {
        vector<vector<int>> adj(n + 1);
        for (auto& e : edges) {
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }

        vector<int> compId(n + 1, -1);
        int numComponents = 0;

        // find components and check bipartite
        for (int start = 1; start <= n; start++) {
            if (compId[start] != -1) continue;
            int cid = numComponents++;
            vector<int> color(n + 1, -1);
            color[start] = 0;
            compId[start] = cid;
            queue<int> q;
            q.push(start);
            while (!q.empty()) {
                int u = q.front(); q.pop();
                for (int v : adj[u]) {
                    if (color[v] == -1) {
                        color[v] = 1 - color[u];
                        compId[v] = cid;
                        q.push(v);
                    } else if (color[v] == color[u]) {
                        return -1;
                    }
                }
            }
        }

        vector<int> bestForComp(numComponents, 0);
        for (int u = 1; u <= n; u++) {
            int depth = bfsMaxDepth(u, adj, n);
            bestForComp[compId[u]] = max(bestForComp[compId[u]], depth + 1);
        }

        int answer = 0;
        for (int v : bestForComp) answer += v;

        return answer;
    }
};
