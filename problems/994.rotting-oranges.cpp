// @leetcode id=994 questionId=1036 slug=rotting-oranges lang=cpp site=leetcode.com title="Rotting Oranges"
class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        queue<pair<int, int>> bfs;
        int fresh = 0;

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 2) bfs.push({i, j});
                else if (grid[i][j] == 1) fresh++;
            }
        }

        if (fresh == 0) return 0;

        int dr[] = {-1, 1, 0, 0};
        int dc[] = {0, 0, -1, 1};
        int minutes = 0;

        while (!bfs.empty()) {
            int sz = bfs.size();
            bool advanced = false;
            for (int k = 0; k < sz; k++) {
                auto [r, c] = bfs.front(); bfs.pop();
                for (int d = 0; d < 4; d++) {
                    int nr = r + dr[d], nc = c + dc[d];
                    if (nr < 0 || nr >= m || nc < 0 || nc >= n) continue;
                    if (grid[nr][nc] != 1) continue;
                    grid[nr][nc] = 2;
                    fresh--;
                    bfs.push({nr, nc});
                    advanced = true;
                }
            }
            if (advanced) minutes++;
        }

        return fresh == 0 ? minutes : -1;
    }
};
