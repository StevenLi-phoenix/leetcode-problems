// @leetcode id=2392 questionId=2472 slug=build-a-matrix-with-conditions lang=cpp site=leetcode.com title="Build a Matrix With Conditions"
class Solution {
public:
    vector<int> topoSort(int k, vector<vector<int>>& conditions) {
        vector<vector<int>> adj(k + 1);
        vector<int> indeg(k + 1, 0);
        for (auto& c : conditions) {
            adj[c[0]].push_back(c[1]);
            indeg[c[1]]++;
        }

        queue<int> q;
        for (int i = 1; i <= k; i++) if (indeg[i] == 0) q.push(i);

        vector<int> order;
        while (!q.empty()) {
            int u = q.front();
            q.pop();
            order.push_back(u);
            for (int v : adj[u]) {
                if (--indeg[v] == 0) q.push(v);
            }
        }

        if ((int)order.size() != k) return {};
        return order;
    }

    vector<vector<int>> buildMatrix(int k, vector<vector<int>>& rowConditions, vector<vector<int>>& colConditions) {
        vector<int> rowOrder = topoSort(k, rowConditions);
        vector<int> colOrder = topoSort(k, colConditions);

        if (rowOrder.empty() || colOrder.empty()) return {};

        vector<int> rowPos(k + 1), colPos(k + 1);
        for (int i = 0; i < k; i++) rowPos[rowOrder[i]] = i;
        for (int i = 0; i < k; i++) colPos[colOrder[i]] = i;

        vector<vector<int>> matrix(k, vector<int>(k, 0));
        for (int v = 1; v <= k; v++) {
            matrix[rowPos[v]][colPos[v]] = v;
        }

        return matrix;
    }
};
