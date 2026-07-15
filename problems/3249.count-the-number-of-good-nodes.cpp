// @leetcode id=3249 questionId=3486 slug=count-the-number-of-good-nodes lang=cpp site=leetcode.com title="Count the Number of Good Nodes"
class Solution {
public:
    int countGoodNodes(vector<vector<int>>& edges) {
        int n = edges.size() + 1;
        vector<vector<int>> adj(n);
        for (auto& e : edges) {
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }

        vector<int> parent(n, -1), order;
        order.reserve(n);
        vector<int> stack;
        stack.push_back(0);
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

        vector<int> size(n, 1);
        int good = 0;
        for (int i = (int)order.size() - 1; i >= 0; i--) {
            int u = order[i];
            int childSize = -1;
            bool ok = true;
            for (int v : adj[u]) {
                if (v == parent[u]) continue;
                size[u] += size[v];
                if (childSize == -1) childSize = size[v];
                else if (childSize != size[v]) ok = false;
            }
            if (ok) good++;
        }
        return good;
    }
};
