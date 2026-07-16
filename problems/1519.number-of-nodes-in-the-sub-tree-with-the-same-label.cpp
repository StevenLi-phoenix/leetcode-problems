// @leetcode id=1519 questionId=1643 slug=number-of-nodes-in-the-sub-tree-with-the-same-label lang=cpp site=leetcode.com title="Number of Nodes in the Sub-Tree With the Same Label"
class Solution {
public:
    vector<int> countSubTrees(int n, vector<vector<int>>& edges, string labels) {
        vector<vector<int>> adj(n);
        for (auto& e : edges) {
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }

        vector<int> result(n, 0);
        vector<array<int, 26>> count(n);
        vector<int> parent(n, -1);
        vector<int> order;
        order.reserve(n);
        vector<int> stack = {0};
        vector<bool> visited(n, false);
        visited[0] = true;
        while (!stack.empty()) {
            int u = stack.back(); stack.pop_back();
            order.push_back(u);
            for (int v : adj[u]) {
                if (!visited[v]) {
                    visited[v] = true;
                    parent[v] = u;
                    stack.push_back(v);
                }
            }
        }

        for (int u : order) count[u].fill(0);

        for (int i = (int)order.size() - 1; i >= 0; i--) {
            int u = order[i];
            count[u][labels[u] - 'a']++;
            result[u] = count[u][labels[u] - 'a'];
            if (parent[u] != -1) {
                for (int c = 0; c < 26; c++) count[parent[u]][c] += count[u][c];
            }
        }
        return result;
    }
};
