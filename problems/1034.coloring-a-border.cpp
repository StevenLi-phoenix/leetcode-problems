// @leetcode id=1034 questionId=1104 slug=coloring-a-border lang=cpp site=leetcode.com title="Coloring A Border"
class Solution {
public:
    vector<vector<int>> colorBorder(vector<vector<int>>& grid, int row, int col, int color) {
        int m = grid.size(), n = grid[0].size();
        int originalColor = grid[row][col];
        vector<vector<bool>> visited(m, vector<bool>(n, false));
        vector<pair<int,int>> component;
        
        // BFS to find all cells in the connected component
        queue<pair<int,int>> q;
        q.push({row, col});
        visited[row][col] = true;
        int dx[] = {0, 0, 1, -1};
        int dy[] = {1, -1, 0, 0};
        
        while (!q.empty()) {
            auto [r, c] = q.front(); q.pop();
            component.push_back({r, c});
            for (int d = 0; d < 4; d++) {
                int nr = r + dx[d], nc = c + dy[d];
                if (nr >= 0 && nr < m && nc >= 0 && nc < n && !visited[nr][nc] && grid[nr][nc] == originalColor) {
                    visited[nr][nc] = true;
                    q.push({nr, nc});
                }
            }
        }
        
        // Color border cells
        for (auto [r, c] : component) {
            // Check if it's a border cell
            bool isBorder = (r == 0 || r == m-1 || c == 0 || c == n-1);
            if (!isBorder) {
                for (int d = 0; d < 4; d++) {
                    int nr = r + dx[d], nc = c + dy[d];
                    if (!visited[nr][nc]) { isBorder = true; break; }
                }
            }
            if (isBorder) grid[r][c] = color;
        }
        
        return grid;
    }
};
