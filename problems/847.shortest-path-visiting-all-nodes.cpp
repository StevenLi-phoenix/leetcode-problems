// @leetcode id=847 questionId=877 slug=shortest-path-visiting-all-nodes lang=cpp site=leetcode.com title="Shortest Path Visiting All Nodes"
class Solution {
public:
    int shortestPathLength(vector<vector<int>>& graph) {
        int n = graph.size();
        int full = (1 << n) - 1;

        vector<vector<bool>> visited(1 << n, vector<bool>(n, false));
        queue<tuple<int, int, int>> q; // (mask, node, dist)

        for (int i = 0; i < n; ++i) {
            visited[1 << i][i] = true;
            q.push({1 << i, i, 0});
        }

        while (!q.empty()) {
            auto [mask, node, dist] = q.front();
            q.pop();
            if (mask == full) return dist;

            for (int next : graph[node]) {
                int nextMask = mask | (1 << next);
                if (!visited[nextMask][next]) {
                    visited[nextMask][next] = true;
                    q.push({nextMask, next, dist + 1});
                }
            }
        }
        return -1;
    }
};
