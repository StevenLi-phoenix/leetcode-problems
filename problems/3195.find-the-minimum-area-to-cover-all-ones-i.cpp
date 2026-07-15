// @leetcode id=3195 questionId=3461 slug=find-the-minimum-area-to-cover-all-ones-i lang=cpp site=leetcode.com title="Find the Minimum Area to Cover All Ones I"
class Solution {
public:
    int minimumArea(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        int minR = m, maxR = -1, minC = n, maxC = -1;
        for (int r = 0; r < m; r++) {
            for (int c = 0; c < n; c++) {
                if (grid[r][c] == 1) {
                    minR = min(minR, r);
                    maxR = max(maxR, r);
                    minC = min(minC, c);
                    maxC = max(maxC, c);
                }
            }
        }
        return (maxR - minR + 1) * (maxC - minC + 1);
    }
};
