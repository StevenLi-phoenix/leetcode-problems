// @leetcode id=2872 questionId=3058 slug=maximum-number-of-k-divisible-components lang=cpp site=leetcode.com title="Maximum Number of K-Divisible Components"
class Solution {
public:
    int maxKDivisibleComponents(int n, vector<vector<int>>& edges, vector<int>& values, int k) {
        vector<vector<int>> adj(n);
        for (auto& e : edges) {
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }

        vector<long long> subtreeSum(n, 0);
        vector<int> parent(n, -1);
        vector<int> order;
        order.reserve(n);

        vector<int> stack;
        stack.reserve(n);
        stack.push_back(0);
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

        for (int i = 0; i < n; i++) subtreeSum[i] = values[i];

        int components = 0;
        for (int i = n - 1; i >= 0; i--) {
            int u = order[i];
            if (subtreeSum[u] % k == 0) {
                components++;
            } else if (parent[u] != -1) {
                subtreeSum[parent[u]] += subtreeSum[u];
            }
        }

        return components;
    }
};
