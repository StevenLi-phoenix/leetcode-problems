// @leetcode id=3786 questionId=4072 slug=total-sum-of-interaction-cost-in-tree-groups lang=cpp site=leetcode.com title="Total Sum of Interaction Cost in Tree Groups"
class Solution {
public:
    long long interactionCosts(int n, vector<vector<int>>& edges, vector<int>& group) {
        vector<vector<int>> adj(n);
        for (auto& e : edges) {
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }

        array<long long, 21> total{};
        for (int g : group) total[g]++;

        vector<array<long long, 21>> subCount(n);
        vector<int> parent(n, -1);
        vector<int> order;
        order.reserve(n);
        vector<bool> visited(n, false);

        vector<int> stack = {0};
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

        for (int i = n - 1; i >= 0; i--) {
            int u = order[i];
            subCount[u][group[u]]++;
            if (parent[u] != -1) {
                for (int g = 1; g <= 20; g++) subCount[parent[u]][g] += subCount[u][g];
            }
        }

        long long answer = 0;
        for (int u = 0; u < n; u++) {
            if (parent[u] == -1) continue;
            for (int g = 1; g <= 20; g++) {
                long long inSub = subCount[u][g];
                long long outSub = total[g] - inSub;
                answer += inSub * outSub;
            }
        }

        return answer;
    }
};
