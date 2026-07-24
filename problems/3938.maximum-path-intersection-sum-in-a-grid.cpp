// @leetcode id=3938 questionId=3901 slug=maximum-path-intersection-sum-in-a-grid lang=cpp site=leetcode.com title="Maximum Path Intersection Sum in a Grid"
class Solution {
public:
    int maxScore(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        long long best = LLONG_MIN;

        for (int r = 0; r < m; r++) {
            bool rowBoundary = (r == 0 || r == m - 1);
            long long extend = grid[r][0];
            for (int p = 1; p < n; p++) {
                long long extendGE2 = extend + grid[r][p];
                long long newExtend = max((long long)grid[r][p], extend + grid[r][p]);
                bool cellBoundary = rowBoundary || (p == 0 || p == n - 1);
                long long candidate = cellBoundary ? extendGE2 : newExtend;
                best = max(best, candidate);
                extend = newExtend;
            }
        }

        for (int c = 0; c < n; c++) {
            bool colBoundary = (c == 0 || c == n - 1);
            long long extend = grid[0][c];
            for (int p = 1; p < m; p++) {
                long long extendGE2 = extend + grid[p][c];
                long long newExtend = max((long long)grid[p][c], extend + grid[p][c]);
                bool cellBoundary = colBoundary || (p == 0 || p == m - 1);
                long long candidate = cellBoundary ? extendGE2 : newExtend;
                best = max(best, candidate);
                extend = newExtend;
            }
        }

        return (int)best;
    }
};
