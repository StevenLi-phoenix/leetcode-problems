// @leetcode id=2577 questionId=2711 slug=minimum-time-to-visit-a-cell-in-a-grid lang=cpp site=leetcode.com title="Minimum Time to Visit a Cell In a Grid"
class Solution {
public:
    int minimumTime(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        if (grid[0][1] > 1 && grid[1][0] > 1) return -1;

        vector<vector<int>> dist(m, vector<int>(n, INT_MAX));
        dist[0][0] = 0;
        priority_queue<tuple<int,int,int>, vector<tuple<int,int,int>>, greater<>> pq;
        pq.push({0, 0, 0});

        int dr[4] = {-1,1,0,0};
        int dc[4] = {0,0,-1,1};

        while (!pq.empty()) {
            auto [d, r, c] = pq.top();
            pq.pop();
            if (d > dist[r][c]) continue;
            if (r == m - 1 && c == n - 1) return d;

            for (int k = 0; k < 4; k++) {
                int nr = r + dr[k], nc = c + dc[k];
                if (nr < 0 || nr >= m || nc < 0 || nc >= n) continue;

                int waitTime = grid[nr][nc] - d - 1;
                int arrive = d + 1;
                if (waitTime > 0) {
                    // need same parity as grid[nr][nc]; from time d+1, if parity mismatch add 1
                    arrive = grid[nr][nc];
                    if ((arrive - (d + 1)) % 2 != 0) arrive++;
                }

                if (arrive < dist[nr][nc]) {
                    dist[nr][nc] = arrive;
                    pq.push({arrive, nr, nc});
                }
            }
        }

        return -1;
    }
};
