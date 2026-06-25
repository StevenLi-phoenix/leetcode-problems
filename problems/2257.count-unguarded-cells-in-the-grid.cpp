// @leetcode id=2257 questionId=2343 slug=count-unguarded-cells-in-the-grid lang=cpp site=leetcode.com title="Count Unguarded Cells in the Grid"
class Solution {
    public:
    int countUnguarded(int m, int n, vector<vector<int>>& guards, vector<vector<int>>& walls) {
    vector<vector<int>> grid(m, vector<int>(n, 0));
    for (auto& g : guards) grid[g[0]][g[1]] = 1;
    for (auto& w : walls) grid[w[0]][w[1]] = 2;
    int dx[] = {0,0,1,-1};
    int dy[] = {1,-1,0,0};
    for (auto& g : guards) {
    for (int d = 0; d < 4; d++) {
    int x = g[0] + dx[d], y = g[1] + dy[d];
    while (x >= 0 && x < m && y >= 0 && y < n && grid[x][y] != 1 && grid[x][y] != 2) {
    grid[x][y] = 3;
    x += dx[d]; y += dy[d];
    }
    }
    }
    int cnt = 0;
    for (int i = 0; i < m; i++)
    for (int j = 0; j < n; j++)
    if (grid[i][j] == 0) cnt++;
    return cnt;
    }
    };
