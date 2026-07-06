// @leetcode id=1219 questionId=1331 slug=path-with-maximum-gold lang=cpp site=leetcode.com title="Path with Maximum Gold"
class Solution {
public:
    int getMaximumGold(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        int best = 0;

        function<int(int, int)> dfs = [&](int r, int c) -> int {
            if (r < 0 || r >= m || c < 0 || c >= n || grid[r][c] == 0) return 0;
            int gold = grid[r][c];
            grid[r][c] = 0;
            int maxNext = 0;
            maxNext = max(maxNext, dfs(r + 1, c));
            maxNext = max(maxNext, dfs(r - 1, c));
            maxNext = max(maxNext, dfs(r, c + 1));
            maxNext = max(maxNext, dfs(r, c - 1));
            grid[r][c] = gold;
            return gold + maxNext;
        };

        for (int r = 0; r < m; ++r) {
            for (int c = 0; c < n; ++c) {
                if (grid[r][c] != 0) {
                    best = max(best, dfs(r, c));
                }
            }
        }
        return best;
    }
};
