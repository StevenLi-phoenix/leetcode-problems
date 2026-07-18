// @leetcode id=834 questionId=863 slug=sum-of-distances-in-tree lang=cpp site=leetcode.com title="Sum of Distances in Tree"
class Solution {
public:
    vector<int> sumOfDistancesInTree(int n, vector<vector<int>>& edges) {
        vector<vector<int>> adj(n);
        for (auto& e : edges) {
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }

        vector<long long> count(n, 1);
        vector<long long> ans(n, 0);

        // iterative post-order to compute subtree sizes and initial dist sum from root 0
        vector<int> parent(n, -1);
        vector<int> order;
        order.reserve(n);
        vector<int> stack = {0};
        vector<bool> visited(n, false);
        visited[0] = true;
        while (!stack.empty()) {
            int u = stack.back();
            stack.pop_back();
            order.push_back(u);
            for (int v : adj[u]) {
                if (!visited[v]) {
                    visited[v] = true;
                    parent[v] = u;
                    stack.push_back(v);
                }
            }
        }

        for (int i = order.size() - 1; i >= 0; i--) {
            int u = order[i];
            for (int v : adj[u]) {
                if (v != parent[u]) {
                    count[u] += count[v];
                    ans[u] += ans[v] + count[v];
                }
            }
        }

        for (int i = 0; i < (int)order.size(); i++) {
            int u = order[i];
            if (u == 0) continue;
            int p = parent[u];
            ans[u] = ans[p] - count[u] + (n - count[u]);
        }

        vector<int> result(n);
        for (int i = 0; i < n; i++) result[i] = (int)ans[i];
        return result;
    }
};
