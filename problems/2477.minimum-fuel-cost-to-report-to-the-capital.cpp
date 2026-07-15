// @leetcode id=2477 questionId=2568 slug=minimum-fuel-cost-to-report-to-the-capital lang=cpp site=leetcode.com title="Minimum Fuel Cost to Report to the Capital"
class Solution {
public:
    long long minimumFuelCost(vector<vector<int>>& roads, int seats) {
        int n = roads.size() + 1;
        vector<vector<int>> adj(n);
        for (auto& r : roads) {
            adj[r[0]].push_back(r[1]);
            adj[r[1]].push_back(r[0]);
        }

        vector<int> parent(n, -1), order;
        order.reserve(n);
        vector<bool> visited(n, false);
        vector<int> stack;
        stack.push_back(0);
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

        vector<long long> size(n, 1);
        long long fuel = 0;
        for (int i = (int)order.size() - 1; i >= 0; i--) {
            int u = order[i];
            if (u == 0) continue;
            size[parent[u]] += size[u];
            fuel += (size[u] + seats - 1) / seats;
        }
        return fuel;
    }
};
