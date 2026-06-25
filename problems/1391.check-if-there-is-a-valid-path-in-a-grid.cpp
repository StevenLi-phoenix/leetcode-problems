// @leetcode id=1391 questionId=1507 slug=check-if-there-is-a-valid-path-in-a-grid lang=cpp site=leetcode.com title="Check if There is a Valid Path in a Grid"
class Solution {
    public:
    bool hasValidPath(vector<vector<int>>& grid) {
    int m = grid.size(), n = grid[0].size();
    // directions: 0=left, 1=right, 2=up, 3=down
    // dr, dc for each direction
    vector<int> dr = {0, 0, -1, 1};
    vector<int> dc = {-1, 1, 0, 0};
    // opposite direction index
    vector<int> opp = {1, 0, 3, 2};
    // which directions each street type connects
    // street type 1-indexed
    vector<vector<int>> connects = {
    {}, // placeholder for index 0
    {0, 1}, // 1: left-right
    {2, 3}, // 2: up-down
    {0, 3}, // 3: left-down
    {1, 3}, // 4: right-down
    {0, 2}, // 5: left-up
    {1, 2}  // 6: right-up
    };
    vector<vector<bool>> visited(m, vector<bool>(n, false));
    queue<pair<int,int>> q;
    q.push({0, 0});
    visited[0][0] = true;
    while (!q.empty()) {
    auto [r, c] = q.front();
    q.pop();
    if (r == m-1 && c == n-1) return true;
    int street = grid[r][c];
    for (int dir : connects[street]) {
    int nr = r + dr[dir];
    int nc = c + dc[dir];
    if (nr < 0 || nr >= m || nc < 0 || nc >= n) continue;
    if (visited[nr][nc]) continue;
    int nstreet = grid[nr][nc];
    bool canEnter = false;
    for (int ndir : connects[nstreet]) {
    if (ndir == opp[dir]) { canEnter = true; break; }
    }
    if (canEnter) {
    visited[nr][nc] = true;
    q.push({nr, nc});
    }
    }
    }
    return false;
    }
    };
