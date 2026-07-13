// @leetcode id=695 questionId=695 slug=max-area-of-island lang=cpp site=leetcode.com title="Max Area of Island"
class Solution {
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        int dx[4] = {0, 0, 1, -1};
        int dy[4] = {1, -1, 0, 0};
        int best = 0;

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] != 1) continue;
                int area = 0;
                queue<pair<int, int>> q;
                q.push({i, j});
                grid[i][j] = 0;
                while (!q.empty()) {
                    auto [r, c] = q.front();
                    q.pop();
                    area++;
                    for (int d = 0; d < 4; d++) {
                        int nr = r + dx[d], nc = c + dy[d];
                        if (nr >= 0 && nr < m && nc >= 0 && nc < n && grid[nr][nc] == 1) {
                            grid[nr][nc] = 0;
                            q.push({nr, nc});
                        }
                    }
                }
                best = max(best, area);
            }
        }
        return best;
    }
};
