// @leetcode id=2467 questionId=2564 slug=most-profitable-path-in-a-tree lang=cpp site=leetcode.com title="Most Profitable Path in a Tree"
class Solution {
public:
    int mostProfitablePath(vector<vector<int>>& edges, int bob, vector<int>& amount) {
        int n = amount.size();
        vector<vector<int>> adj(n);
        for (auto& e : edges) {
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }

        vector<int> parent(n, -1);
        vector<bool> visited(n, false);
        vector<int> order;
        order.reserve(n);
        vector<int> stack = {0};
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

        vector<int> bobTime(n, INT_MAX);
        int cur = bob, t = 0;
        while (cur != -1) {
            bobTime[cur] = t++;
            cur = parent[cur];
        }

        vector<long long> aliceIncome(n, 0);
        vector<int> aliceTime(n, 0);
        int best = INT_MIN;

        for (int u : order) {
            long long income = (u == 0) ? 0 : aliceIncome[parent[u]];
            int at = (u == 0) ? 0 : aliceTime[parent[u]] + 1;
            if (at < bobTime[u]) {
                income += amount[u];
            } else if (at == bobTime[u]) {
                income += amount[u] / 2;
            }
            aliceIncome[u] = income;
            aliceTime[u] = at;

            bool isLeaf = (adj[u].size() == 1 && u != 0) || (u == 0 && adj[u].empty());
            if (isLeaf) best = max(best, (int)income);
        }
        return best;
    }
};
