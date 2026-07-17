// @leetcode id=1368 questionId=1485 slug=minimum-cost-to-make-at-least-one-valid-path-in-a-grid lang=cpp site=leetcode.com title="Minimum Cost to Make at Least One Valid Path in a Grid"
class Solution {
public:
    int minCost(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        vector<vector<int>> dist(m, vector<int>(n, INT_MAX));
        dist[0][0] = 0;
        deque<pair<int,int>> dq;
        dq.push_back({0, 0});

        int dr[5] = {0, 0, 0, 1, -1};
        int dc[5] = {0, 1, -1, 0, 0};

        while (!dq.empty()) {
            auto [r, c] = dq.front();
            dq.pop_front();

            for (int dir = 1; dir <= 4; dir++) {
                int nr = r + dr[dir], nc = c + dc[dir];
                if (nr < 0 || nr >= m || nc < 0 || nc >= n) continue;
                int cost = (grid[r][c] == dir) ? 0 : 1;
                if (dist[r][c] + cost < dist[nr][nc]) {
                    dist[nr][nc] = dist[r][c] + cost;
                    if (cost == 0) dq.push_front({nr, nc});
                    else dq.push_back({nr, nc});
                }
            }
        }

        return dist[m - 1][n - 1];
    }
};
