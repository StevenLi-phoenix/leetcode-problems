// @leetcode id=407 questionId=407 slug=trapping-rain-water-ii lang=cpp site=leetcode.com title="Trapping Rain Water II"
class Solution {
public:
    int trapRainWater(vector<vector<int>>& heightMap) {
        int m = heightMap.size();
        if (m == 0) return 0;
        int n = heightMap[0].size();
        if (n == 0) return 0;

        vector<vector<bool>> visited(m, vector<bool>(n, false));
        priority_queue<tuple<int,int,int>, vector<tuple<int,int,int>>, greater<>> pq;

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (i == 0 || i == m - 1 || j == 0 || j == n - 1) {
                    pq.push({heightMap[i][j], i, j});
                    visited[i][j] = true;
                }
            }
        }

        int dirs[4][2] = {{0,1},{0,-1},{1,0},{-1,0}};
        int water = 0;

        while (!pq.empty()) {
            auto [h, x, y] = pq.top();
            pq.pop();

            for (auto& d : dirs) {
                int nx = x + d[0], ny = y + d[1];
                if (nx < 0 || nx >= m || ny < 0 || ny >= n || visited[nx][ny]) continue;
                visited[nx][ny] = true;
                water += max(0, h - heightMap[nx][ny]);
                pq.push({max(h, heightMap[nx][ny]), nx, ny});
            }
        }

        return water;
    }
};
