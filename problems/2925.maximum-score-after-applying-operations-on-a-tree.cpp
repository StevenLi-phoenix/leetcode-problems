// @leetcode id=2925 questionId=3191 slug=maximum-score-after-applying-operations-on-a-tree lang=cpp site=leetcode.com title="Maximum Score After Applying Operations on a Tree"
class Solution {
public:
    long long maximumScoreAfterOperations(vector<vector<int>>& edges, vector<int>& values) {
        int n = values.size();
        vector<vector<int>> adj(n);
        for (auto& e : edges) {
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
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

        vector<long long> total(n, 0), removeConstrained(n, 0);
        for (int i = (int)order.size() - 1; i >= 0; i--) {
            int u = order[i];
            long long sumChildTotal = 0, sumChildConstrained = 0;
            bool isLeaf = true;
            for (int v : adj[u]) {
                if (v == parent[u]) continue;
                isLeaf = false;
                sumChildTotal += total[v];
                sumChildConstrained += removeConstrained[v];
            }
            total[u] = values[u] + sumChildTotal;
            if (isLeaf) {
                removeConstrained[u] = 0;
            } else {
                long long optionKeep = sumChildTotal;
                long long optionRemove = values[u] + sumChildConstrained;
                removeConstrained[u] = max(optionKeep, optionRemove);
            }
        }

        return removeConstrained[0];
    }
};
