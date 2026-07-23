// @leetcode id=463 questionId=463 slug=island-perimeter lang=cpp site=leetcode.com title="Island Perimeter"
class Solution {
public:
    int islandPerimeter(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        int perimeter = 0;

        for (int r = 0; r < m; r++) {
            for (int c = 0; c < n; c++) {
                if (grid[r][c] == 1) {
                    perimeter += 4;
                    if (r > 0 && grid[r - 1][c] == 1) perimeter -= 2;
                    if (c > 0 && grid[r][c - 1] == 1) perimeter -= 2;
                }
            }
        }

        return perimeter;
    }
};
