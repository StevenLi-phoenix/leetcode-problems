// @leetcode id=2146 questionId=2250 slug=k-highest-ranked-items-within-a-price-range lang=cpp site=leetcode.com title="K Highest Ranked Items Within a Price Range"
class Solution {
public:
    vector<vector<int>> highestRankedKItems(vector<vector<int>>& grid, vector<int>& pricing, vector<int>& start, int k) {
        int m = grid.size(), n = grid[0].size();
        int low = pricing[0], high = pricing[1];

        vector<vector<bool>> visited(m, vector<bool>(n, false));
        queue<tuple<int,int,int>> q; // r, c, dist
        q.push({start[0], start[1], 0});
        visited[start[0]][start[1]] = true;

        vector<array<int,4>> items; // dist, price, row, col

        int dr[] = {-1, 1, 0, 0};
        int dc[] = {0, 0, -1, 1};

        while (!q.empty()) {
            auto [r, c, dist] = q.front();
            q.pop();

            int price = grid[r][c];
            if (price >= low && price <= high) {
                items.push_back({dist, price, r, c});
            }

            for (int d = 0; d < 4; d++) {
                int nr = r + dr[d], nc = c + dc[d];
                if (nr < 0 || nr >= m || nc < 0 || nc >= n) continue;
                if (visited[nr][nc] || grid[nr][nc] == 0) continue;
                visited[nr][nc] = true;
                q.push({nr, nc, dist + 1});
            }
        }

        sort(items.begin(), items.end());

        vector<vector<int>> result;
        for (int i = 0; i < (int)items.size() && i < k; i++) {
            result.push_back({items[i][2], items[i][3]});
        }
        return result;
    }
};
