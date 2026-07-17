// @leetcode id=1568 questionId=1691 slug=minimum-number-of-days-to-disconnect-island lang=cpp site=leetcode.com title="Minimum Number of Days to Disconnect Island"
class Solution {
public:
    int countIslands(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        vector<vector<bool>> visited(m, vector<bool>(n, false));
        int islands = 0;
        int dr[4] = {-1, 1, 0, 0};
        int dc[4] = {0, 0, -1, 1};

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 1 && !visited[i][j]) {
                    islands++;
                    queue<pair<int,int>> q;
                    q.push({i, j});
                    visited[i][j] = true;
                    while (!q.empty()) {
                        auto [r, c] = q.front(); q.pop();
                        for (int k = 0; k < 4; k++) {
                            int nr = r + dr[k], nc = c + dc[k];
                            if (nr >= 0 && nr < m && nc >= 0 && nc < n && grid[nr][nc] == 1 && !visited[nr][nc]) {
                                visited[nr][nc] = true;
                                q.push({nr, nc});
                            }
                        }
                    }
                }
            }
        }
        return islands;
    }

    int minDays(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        int islands = countIslands(grid);
        if (islands != 1) return 0;

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 1) {
                    grid[i][j] = 0;
                    int cnt = countIslands(grid);
                    grid[i][j] = 1;
                    if (cnt != 1) return 1;
                }
            }
        }

        return 2;
    }
};
