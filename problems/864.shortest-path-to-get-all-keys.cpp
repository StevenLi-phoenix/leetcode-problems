// @leetcode id=864 questionId=895 slug=shortest-path-to-get-all-keys lang=cpp site=leetcode.com title="Shortest Path to Get All Keys"
class Solution {
public:
    int shortestPathAllKeys(vector<string>& grid) {
        int m = grid.size(), n = grid[0].size();
        int sr = -1, sc = -1, numKeys = 0;

        for (int r = 0; r < m; r++) {
            for (int c = 0; c < n; c++) {
                char ch = grid[r][c];
                if (ch == '@') { sr = r; sc = c; }
                else if (islower(ch)) numKeys = max(numKeys, ch - 'a' + 1);
            }
        }

        int fullMask = (1 << numKeys) - 1;
        vector<vector<vector<bool>>> visited(m, vector<vector<bool>>(n, vector<bool>(1 << numKeys, false)));
        queue<tuple<int,int,int,int>> q; // r,c,mask,dist
        visited[sr][sc][0] = true;
        q.push({sr, sc, 0, 0});

        int dr[4] = {-1,1,0,0};
        int dc[4] = {0,0,-1,1};

        while (!q.empty()) {
            auto [r, c, mask, dist] = q.front(); q.pop();
            if (mask == fullMask) return dist;

            for (int d = 0; d < 4; d++) {
                int nr = r + dr[d], nc = c + dc[d];
                if (nr < 0 || nr >= m || nc < 0 || nc >= n) continue;
                char ch = grid[nr][nc];
                if (ch == '#') continue;
                int nmask = mask;
                if (isupper(ch) && !(mask & (1 << (ch - 'A')))) continue; // locked
                if (islower(ch)) nmask |= (1 << (ch - 'a'));

                if (!visited[nr][nc][nmask]) {
                    visited[nr][nc][nmask] = true;
                    q.push({nr, nc, nmask, dist + 1});
                }
            }
        }

        return -1;
    }
};
