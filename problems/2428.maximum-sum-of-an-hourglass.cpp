// @leetcode id=2428 questionId=2508 slug=maximum-sum-of-an-hourglass lang=cpp site=leetcode.com title="Maximum Sum of an Hourglass"
class Solution {
public:
    int maxSum(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        int best = 0;
        for (int r = 0; r + 2 < m; r++) {
            for (int c = 0; c + 2 < n; c++) {
                int sum = grid[r][c] + grid[r][c + 1] + grid[r][c + 2]
                        + grid[r + 1][c + 1]
                        + grid[r + 2][c] + grid[r + 2][c + 1] + grid[r + 2][c + 2];
                best = max(best, sum);
            }
        }
        return best;
    }
};
