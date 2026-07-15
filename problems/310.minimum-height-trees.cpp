// @leetcode id=310 questionId=310 slug=minimum-height-trees lang=cpp site=leetcode.com title="Minimum Height Trees"
class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        if (n == 1) return {0};

        vector<vector<int>> adj(n);
        vector<int> degree(n, 0);
        for (auto& e : edges) {
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
            degree[e[0]]++;
            degree[e[1]]++;
        }

        queue<int> leaves;
        for (int i = 0; i < n; i++) {
            if (degree[i] == 1) leaves.push(i);
        }

        int remaining = n;
        vector<int> current;
        while (remaining > 2) {
            int leafCount = leaves.size();
            remaining -= leafCount;
            for (int i = 0; i < leafCount; i++) {
                int leaf = leaves.front(); leaves.pop();
                for (int nb : adj[leaf]) {
                    degree[nb]--;
                    if (degree[nb] == 1) leaves.push(nb);
                }
            }
        }

        vector<int> ans;
        while (!leaves.empty()) {
            ans.push_back(leaves.front());
            leaves.pop();
        }
        return ans;
    }
};
