// @leetcode id=1293 questionId=1414 slug=shortest-path-in-a-grid-with-obstacles-elimination lang=cpp site=leetcode.com title="Shortest Path in a Grid with Obstacles Elimination"
class Solution {
public:
    int shortestPath(vector<vector<int>>& grid, int k) {
        int m = grid.size(), n = grid[0].size();
        k = min(k, m + n); // eliminating more obstacles than the path length can ever need is pointless
        vector<vector<int>> bestK(m, vector<int>(n, -1));
        bestK[0][0] = k;

        queue<tuple<int, int, int>> q;
        q.push({0, 0, k});
        int steps = 0;
        int dr[] = {0, 0, 1, -1};
        int dc[] = {1, -1, 0, 0};

        while (!q.empty()) {
            int size = q.size();
            for (int i = 0; i < size; i++) {
                auto [r, c, rem] = q.front(); q.pop();
                if (r == m - 1 && c == n - 1) return steps;
                for (int d = 0; d < 4; d++) {
                    int nr = r + dr[d], nc = c + dc[d];
                    if (nr < 0 || nr >= m || nc < 0 || nc >= n) continue;
                    int nrem = rem - grid[nr][nc];
                    if (nrem < 0) continue;
                    if (nrem <= bestK[nr][nc]) continue;
                    bestK[nr][nc] = nrem;
                    q.push({nr, nc, nrem});
                }
            }
            steps++;
        }
        return -1;
    }
};
