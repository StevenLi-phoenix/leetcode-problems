// @leetcode id=3593 questionId=3909 slug=minimum-increments-to-equalize-leaf-paths lang=cpp site=leetcode.com title="Minimum Increments to Equalize Leaf Paths"
class Solution {
public:
    int minIncrease(int n, vector<vector<int>>& edges, vector<int>& cost) {
        vector<vector<int>> adj(n);
        for (auto& e : edges) {
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }

        vector<long long> pathSum(n, 0);
        vector<long long> incCount(n, 0);

        vector<int> parent(n, -1);
        vector<int> order;
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

        for (int i = (int)order.size() - 1; i >= 0; i--) {
            int u = order[i];
            vector<int> children;
            for (int v : adj[u]) {
                if (v != parent[u]) children.push_back(v);
            }
            if (children.empty()) {
                pathSum[u] = cost[u];
                incCount[u] = 0;
                continue;
            }
            long long target = 0;
            for (int c : children) target = max(target, pathSum[c]);
            long long total = 0;
            for (int c : children) {
                total += incCount[c];
                if (pathSum[c] < target) total += 1;
            }
            pathSum[u] = target + cost[u];
            incCount[u] = total;
        }

        return (int)incCount[0];
    }
};
