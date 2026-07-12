// @leetcode id=3619 questionId=3823 slug=count-islands-with-total-value-divisible-by-k lang=cpp site=leetcode.com title="Count Islands With Total Value Divisible by K"
class Solution {
public:
    int countIslands(vector<vector<int>>& grid, int k) {
        int m = grid.size(), n = grid[0].size();
        vector<vector<bool>> visited(m, vector<bool>(n, false));
        int dr[4] = {-1, 1, 0, 0}, dc[4] = {0, 0, -1, 1};
        int count = 0;

        for (int r = 0; r < m; r++) {
            for (int c = 0; c < n; c++) {
                if (grid[r][c] == 0 || visited[r][c]) continue;
                // Iterative BFS avoids recursion-depth risk (m*n up to 1e5).
                long long sum = 0;
                queue<pair<int,int>> q;
                q.push({r, c});
                visited[r][c] = true;
                while (!q.empty()) {
                    auto [cr, cc] = q.front(); q.pop();
                    sum += grid[cr][cc];
                    for (int d = 0; d < 4; d++) {
                        int nr = cr + dr[d], nc = cc + dc[d];
                        if (nr < 0 || nr >= m || nc < 0 || nc >= n) continue;
                        if (visited[nr][nc] || grid[nr][nc] == 0) continue;
                        visited[nr][nc] = true;
                        q.push({nr, nc});
                    }
                }
                if (sum % k == 0) count++;
            }
        }
        return count;
    }
};
