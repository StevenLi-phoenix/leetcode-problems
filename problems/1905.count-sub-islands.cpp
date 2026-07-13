// @leetcode id=1905 questionId=2035 slug=count-sub-islands lang=cpp site=leetcode.com title="Count Sub Islands"
class Solution {
public:
    int countSubIslands(vector<vector<int>>& grid1, vector<vector<int>>& grid2) {
        int m = grid1.size(), n = grid1[0].size();
        vector<vector<char>> visited(m, vector<char>(n, 0));
        int dx[4] = {0, 0, 1, -1};
        int dy[4] = {1, -1, 0, 0};
        int count = 0;

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid2[i][j] != 1 || visited[i][j]) continue;

                bool isSub = true;
                queue<pair<int, int>> q;
                q.push({i, j});
                visited[i][j] = 1;
                while (!q.empty()) {
                    auto [r, c] = q.front();
                    q.pop();
                    if (grid1[r][c] != 1) isSub = false;
                    for (int d = 0; d < 4; d++) {
                        int nr = r + dx[d], nc = c + dy[d];
                        if (nr >= 0 && nr < m && nc >= 0 && nc < n &&
                            grid2[nr][nc] == 1 && !visited[nr][nc]) {
                            visited[nr][nc] = 1;
                            q.push({nr, nc});
                        }
                    }
                }
                if (isSub) count++;
            }
        }
        return count;
    }
};
