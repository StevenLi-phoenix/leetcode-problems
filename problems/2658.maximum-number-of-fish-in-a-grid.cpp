// @leetcode id=2658 questionId=2764 slug=maximum-number-of-fish-in-a-grid lang=cpp site=leetcode.com title="Maximum Number of Fish in a Grid"
class Solution {
public:
    int findMaxFish(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        vector<vector<bool>> visited(m, vector<bool>(n, false));
        int dr[] = {-1, 1, 0, 0};
        int dc[] = {0, 0, -1, 1};

        int best = 0;
        for (int r = 0; r < m; r++) {
            for (int c = 0; c < n; c++) {
                if (grid[r][c] == 0 || visited[r][c]) continue;

                int total = 0;
                vector<pair<int, int>> stack = {{r, c}};
                visited[r][c] = true;
                while (!stack.empty()) {
                    auto [cr, cc] = stack.back();
                    stack.pop_back();
                    total += grid[cr][cc];
                    for (int d = 0; d < 4; d++) {
                        int nr = cr + dr[d], nc = cc + dc[d];
                        if (nr < 0 || nr >= m || nc < 0 || nc >= n) continue;
                        if (visited[nr][nc] || grid[nr][nc] == 0) continue;
                        visited[nr][nc] = true;
                        stack.push_back({nr, nc});
                    }
                }
                best = max(best, total);
            }
        }
        return best;
    }
};
