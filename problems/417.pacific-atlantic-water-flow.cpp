// @leetcode id=417 questionId=417 slug=pacific-atlantic-water-flow lang=cpp site=leetcode.com title="Pacific Atlantic Water Flow"
class Solution {
public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        int m = heights.size(), n = heights[0].size();
        vector<vector<char>> pacific(m, vector<char>(n, 0));
        vector<vector<char>> atlantic(m, vector<char>(n, 0));
        int dx[4] = {0, 0, 1, -1};
        int dy[4] = {1, -1, 0, 0};

        auto bfs = [&](vector<vector<char>>& visited, queue<pair<int, int>>& q) {
            while (!q.empty()) {
                auto [r, c] = q.front();
                q.pop();
                for (int d = 0; d < 4; d++) {
                    int nr = r + dx[d], nc = c + dy[d];
                    if (nr >= 0 && nr < m && nc >= 0 && nc < n && !visited[nr][nc] &&
                        heights[nr][nc] >= heights[r][c]) {
                        visited[nr][nc] = 1;
                        q.push({nr, nc});
                    }
                }
            }
        };

        queue<pair<int, int>> qp, qa;
        for (int i = 0; i < m; i++) {
            pacific[i][0] = 1;
            qp.push({i, 0});
            atlantic[i][n - 1] = 1;
            qa.push({i, n - 1});
        }
        for (int j = 0; j < n; j++) {
            if (!pacific[0][j]) {
                pacific[0][j] = 1;
                qp.push({0, j});
            }
            if (!atlantic[m - 1][j]) {
                atlantic[m - 1][j] = 1;
                qa.push({m - 1, j});
            }
        }

        bfs(pacific, qp);
        bfs(atlantic, qa);

        vector<vector<int>> result;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (pacific[i][j] && atlantic[i][j]) result.push_back({i, j});
            }
        }
        return result;
    }
};
