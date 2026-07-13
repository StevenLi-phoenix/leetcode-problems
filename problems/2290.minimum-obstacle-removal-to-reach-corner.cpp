// @leetcode id=2290 questionId=2375 slug=minimum-obstacle-removal-to-reach-corner lang=cpp site=leetcode.com title="Minimum Obstacle Removal to Reach Corner"
class Solution {
public:
    int minimumObstacles(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        vector<vector<int>> dist(m, vector<int>(n, INT_MAX));
        dist[0][0] = 0;
        deque<pair<int, int>> dq;
        dq.push_back({0, 0});
        int dx[4] = {0, 0, 1, -1};
        int dy[4] = {1, -1, 0, 0};

        while (!dq.empty()) {
            auto [r, c] = dq.front();
            dq.pop_front();
            for (int d = 0; d < 4; d++) {
                int nr = r + dx[d], nc = c + dy[d];
                if (nr >= 0 && nr < m && nc >= 0 && nc < n) {
                    int weight = grid[nr][nc];
                    int newDist = dist[r][c] + weight;
                    if (newDist < dist[nr][nc]) {
                        dist[nr][nc] = newDist;
                        if (weight == 0) dq.push_front({nr, nc});
                        else dq.push_back({nr, nc});
                    }
                }
            }
        }
        return dist[m - 1][n - 1];
    }
};
