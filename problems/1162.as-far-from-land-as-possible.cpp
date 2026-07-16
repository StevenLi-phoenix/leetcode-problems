// @leetcode id=1162 questionId=1117 slug=as-far-from-land-as-possible lang=cpp site=leetcode.com title="As Far from Land as Possible"
class Solution {
public:
    int maxDistance(vector<vector<int>>& grid) {
        int n = grid.size();
        queue<pair<int,int>> q;
        vector<vector<int>> dist(n, vector<int>(n, -1));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 1) {
                    dist[i][j] = 0;
                    q.push({i, j});
                }
            }
        }

        if (q.empty() || (int)q.size() == n * n) return -1;

        int dirs[4][2] = {{1,0},{-1,0},{0,1},{0,-1}};
        int maxD = 0;
        while (!q.empty()) {
            auto [x, y] = q.front(); q.pop();
            for (auto& d : dirs) {
                int nx = x + d[0], ny = y + d[1];
                if (nx >= 0 && nx < n && ny >= 0 && ny < n && dist[nx][ny] == -1) {
                    dist[nx][ny] = dist[x][y] + 1;
                    maxD = max(maxD, dist[nx][ny]);
                    q.push({nx, ny});
                }
            }
        }
        return maxD;
    }
};
