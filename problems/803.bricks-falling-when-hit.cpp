// @leetcode id=803 questionId=821 slug=bricks-falling-when-hit lang=cpp site=leetcode.com title="Bricks Falling When Hit"
class Solution {
public:
    vector<int> parent;
    vector<int> size_;

    int find(int x) {
        while (parent[x] != x) {
            parent[x] = parent[parent[x]];
            x = parent[x];
        }
        return x;
    }

    void unite(int a, int b) {
        int ra = find(a), rb = find(b);
        if (ra != rb) {
            parent[ra] = rb;
            size_[rb] += size_[ra];
        }
    }

    vector<int> hitBricks(vector<vector<int>>& grid, vector<vector<int>>& hits) {
        int m = grid.size(), n = grid[0].size();
        int top = m * n; // virtual top node
        parent.resize(m * n + 1);
        size_.assign(m * n + 1, 1);
        iota(parent.begin(), parent.end(), 0);

        vector<vector<int>> g = grid;
        for (auto& h : hits) g[h[0]][h[1]] = 0;

        int dr[4] = {-1,1,0,0};
        int dc[4] = {0,0,-1,1};

        auto idx = [&](int r, int c) { return r * n + c; };

        for (int r = 0; r < m; r++) {
            for (int c = 0; c < n; c++) {
                if (!g[r][c]) continue;
                if (r == 0) unite(idx(r, c), top);
                for (int d = 0; d < 4; d++) {
                    int nr = r + dr[d], nc = c + dc[d];
                    if (nr >= 0 && nr < m && nc >= 0 && nc < n && g[nr][nc]) {
                        unite(idx(r, c), idx(nr, nc));
                    }
                }
            }
        }

        int hitsN = hits.size();
        vector<int> result(hitsN, 0);

        for (int i = hitsN - 1; i >= 0; i--) {
            int r = hits[i][0], c = hits[i][1];
            if (grid[r][c] == 0) continue; // no brick originally

            int beforeSize = size_[find(top)];

            g[r][c] = 1;
            if (r == 0) unite(idx(r, c), top);
            for (int d = 0; d < 4; d++) {
                int nr = r + dr[d], nc = c + dc[d];
                if (nr >= 0 && nr < m && nc >= 0 && nc < n && g[nr][nc]) {
                    unite(idx(r, c), idx(nr, nc));
                }
            }

            int afterSize = size_[find(top)];
            int diff = afterSize - beforeSize - 1;
            result[i] = max(0, diff);
        }

        return result;
    }
};
