// @leetcode id=1761 questionId=1887 slug=minimum-degree-of-a-connected-trio-in-a-graph lang=cpp site=leetcode.com title="Minimum Degree of a Connected Trio in a Graph"
class Solution {
public:
    int minTrioDegree(int n, vector<vector<int>>& edges) {
        vector<vector<bool>> adj(n + 1, vector<bool>(n + 1, false));
        vector<int> degree(n + 1, 0);

        for (auto& e : edges) {
            adj[e[0]][e[1]] = adj[e[1]][e[0]] = true;
            degree[e[0]]++;
            degree[e[1]]++;
        }

        int best = INT_MAX;

        for (auto& e : edges) {
            int u = e[0], v = e[1];
            for (int w = 1; w <= n; w++) {
                if (w == u || w == v) continue;
                if (adj[u][w] && adj[v][w]) {
                    int deg = degree[u] + degree[v] + degree[w] - 6;
                    best = min(best, deg);
                }
            }
        }

        return best == INT_MAX ? -1 : best;
    }
};
