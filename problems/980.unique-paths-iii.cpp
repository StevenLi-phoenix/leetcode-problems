// @leetcode id=980 questionId=1022 slug=unique-paths-iii lang=cpp site=leetcode.com title="Unique Paths III"
class Solution {
public:
    int m, n, totalEmpty, count;
    int dirs[4][2] = {{1,0},{-1,0},{0,1},{0,-1}};

    void dfs(vector<vector<int>>& grid, int r, int c, int visited) {
        if (r < 0 || r >= m || c < 0 || c >= n || grid[r][c] == -1) return;
        if (grid[r][c] == 2) {
            if (visited == totalEmpty) count++;
            return;
        }
        int original = grid[r][c];
        grid[r][c] = -1;
        for (auto& d : dirs) {
            dfs(grid, r + d[0], c + d[1], visited + 1);
        }
        grid[r][c] = original;
    }

    int uniquePathsIII(vector<vector<int>>& grid) {
        m = grid.size();
        n = grid[0].size();
        totalEmpty = 0;
        count = 0;
        int startR = 0, startC = 0;

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 0 || grid[i][j] == 1) totalEmpty++;
                if (grid[i][j] == 1) { startR = i; startC = j; }
            }
        }

        dfs(grid, startR, startC, 0);
        return count;
    }
};
