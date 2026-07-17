// @leetcode id=3772 questionId=4151 slug=maximum-subgraph-score-in-a-tree lang=cpp site=leetcode.com title="Maximum Subgraph Score in a Tree"
class Solution {
public:
    vector<int> maxSubgraphScore(int n, vector<vector<int>>& edges, vector<int>& good) {
        vector<vector<int>> adj(n);
        for (auto& e : edges) {
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }

        vector<int> value(n);
        for (int i = 0; i < n; i++) value[i] = good[i] ? 1 : -1;

        vector<int> parent(n, -1);
        vector<int> order;
        order.reserve(n);
        vector<bool> visited(n, false);
        vector<int> stack;
        stack.reserve(n);
        stack.push_back(0);
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

        vector<long long> down(n, 0);
        vector<long long> childSum(n, 0); // sum over children of max(0,down[child])

        for (int i = n - 1; i >= 0; i--) {
            int u = order[i];
            down[u] = value[u] + childSum[u];
            if (parent[u] != -1) {
                childSum[parent[u]] += max(0LL, down[u]);
            }
        }

        vector<long long> up(n, LLONG_MIN);
        for (int u : order) {
            for (int v : adj[u]) {
                if (v == parent[u]) continue;
                long long siblingSum = childSum[u] - max(0LL, down[v]);
                long long parentUpContribution = (up[u] == LLONG_MIN) ? 0 : max(0LL, up[u]);
                up[v] = value[u] + parentUpContribution + siblingSum;
            }
        }

        vector<int> answer(n);
        for (int i = 0; i < n; i++) {
            long long upContribution = (up[i] == LLONG_MIN) ? 0 : max(0LL, up[i]);
            answer[i] = (int)(down[i] + upContribution);
        }

        return answer;
    }
};
