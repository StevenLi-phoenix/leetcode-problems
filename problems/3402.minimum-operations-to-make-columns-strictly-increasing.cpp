// @leetcode id=3402 questionId=3691 slug=minimum-operations-to-make-columns-strictly-increasing lang=cpp site=leetcode.com title="Minimum Operations to Make Columns Strictly Increasing"
class Solution {
public:
    int minimumOperations(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        int total = 0;

        for (int c = 0; c < n; c++) {
            int prev = grid[0][c];
            for (int r = 1; r < m; r++) {
                if (grid[r][c] <= prev) {
                    total += (prev + 1 - grid[r][c]);
                    prev = prev + 1;
                } else {
                    prev = grid[r][c];
                }
            }
        }
        return total;
    }
};
