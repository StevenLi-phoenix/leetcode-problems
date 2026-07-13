// @leetcode id=1091 questionId=1171 slug=shortest-path-in-binary-matrix lang=cpp site=leetcode.com title="Shortest Path in Binary Matrix"
class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n = grid.size();
        if (grid[0][0] != 0 || grid[n - 1][n - 1] != 0) return -1;

        vector<vector<int>> dist(n, vector<int>(n, -1));
        dist[0][0] = 1;
        queue<pair<int, int>> q;
        q.push({0, 0});

        int dx[8] = {-1, -1, -1, 0, 0, 1, 1, 1};
        int dy[8] = {-1, 0, 1, -1, 1, -1, 0, 1};

        while (!q.empty()) {
            auto [r, c] = q.front();
            q.pop();
            if (r == n - 1 && c == n - 1) return dist[r][c];
            for (int d = 0; d < 8; d++) {
                int nr = r + dx[d], nc = c + dy[d];
                if (nr >= 0 && nr < n && nc >= 0 && nc < n && grid[nr][nc] == 0 && dist[nr][nc] == -1) {
                    dist[nr][nc] = dist[r][c] + 1;
                    q.push({nr, nc});
                }
            }
        }
        return -1;
    }
};
