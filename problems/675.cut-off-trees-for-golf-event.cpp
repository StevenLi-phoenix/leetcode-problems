// @leetcode id=675 questionId=675 slug=cut-off-trees-for-golf-event lang=cpp site=leetcode.com title="Cut Off Trees for Golf Event"
class Solution {
public:
    int cutOffTree(vector<vector<int>>& forest) {
        int m = forest.size(), n = forest[0].size();
        vector<tuple<int,int,int>> trees; // (height, row, col)
        for (int r = 0; r < m; r++)
            for (int c = 0; c < n; c++)
                if (forest[r][c] > 1) trees.push_back({forest[r][c], r, c});
        sort(trees.begin(), trees.end());

        auto bfs = [&](int sr, int sc, int tr, int tc) -> int {
            if (sr == tr && sc == tc) return 0;
            vector<vector<bool>> visited(m, vector<bool>(n, false));
            queue<pair<int,int>> q;
            q.push({sr, sc});
            visited[sr][sc] = true;
            int dr[4] = {-1,1,0,0}, dc[4] = {0,0,-1,1};
            int steps = 0;
            while (!q.empty()) {
                steps++;
                int sz = q.size();
                for (int i = 0; i < sz; i++) {
                    auto [r, c] = q.front(); q.pop();
                    for (int d = 0; d < 4; d++) {
                        int nr = r + dr[d], nc = c + dc[d];
                        if (nr < 0 || nr >= m || nc < 0 || nc >= n) continue;
                        if (visited[nr][nc] || forest[nr][nc] == 0) continue;
                        if (nr == tr && nc == tc) return steps;
                        visited[nr][nc] = true;
                        q.push({nr, nc});
                    }
                }
            }
            return -1;
        };

        int curR = 0, curC = 0, total = 0;
        for (auto& [h, r, c] : trees) {
            int d = bfs(curR, curC, r, c);
            if (d == -1) return -1;
            total += d;
            curR = r; curC = c;
        }
        return total;
    }
};
