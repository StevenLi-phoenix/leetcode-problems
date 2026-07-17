// @leetcode id=2192 questionId=1431 slug=all-ancestors-of-a-node-in-a-directed-acyclic-graph lang=cpp site=leetcode.com title="All Ancestors of a Node in a Directed Acyclic Graph"
class Solution {
public:
    void dfs(int u, vector<vector<int>>& adj, vector<bool>& visited) {
        for (int v : adj[u]) {
            if (!visited[v]) {
                visited[v] = true;
                dfs(v, adj, visited);
            }
        }
    }

    vector<vector<int>> getAncestors(int n, vector<vector<int>>& edges) {
        vector<vector<int>> adj(n);
        for (auto& e : edges) adj[e[0]].push_back(e[1]);

        vector<vector<int>> result(n);
        for (int i = 0; i < n; i++) {
            vector<bool> visited(n, false);
            dfs(i, adj, visited);
            for (int j = 0; j < n; j++) {
                if (visited[j]) result[j].push_back(i);
            }
        }
        return result;
    }
};
